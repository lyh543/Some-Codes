% 运行环境：至少 MATLAB R2019a，推荐 MATLAB R2020a

% handles 包含的数据结构：
% keywords           用户输入的关键字
% userChoice         1x3 double，用户的选择（三个 popup_menu 的下标），默认为 0
% rootDirectory      根目录
% modelMatrix        厂家-型号的矩阵
%                    三列为 1厂家 2型号 3厂家型号
% modelRanking       {score, indexCell}，厂家-型号的匹配度排名
% indexMatrix        用户选择型号的目录
%                    五列为  1器件编号  2器件名  3部件名  4图片编号  5页码
% Map_page_name      用户选择型号的页码-名称映射
% Map_page_idx       用户选择型号的页码-下标映射
% informationMatrix  用户选择型号的零件信息
%                    七列为 1页码 2图中序号 3件号 4名称 5数量 6系列号 7主串
% informationRanking    {score, indexCell}，用户选择型号的零件匹配度排名，相同字符串的 index 被归入到同一行的 indexCell 中

% GUI 程序所需要的函数
function varargout = search_user_gui(varargin)

gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
    'gui_Singleton',  gui_Singleton, ...
    'gui_OpeningFcn', @search_user_gui_OpeningFcn, ...
    'gui_OutputFcn',  @search_user_gui_OutputFcn, ...
    'gui_LayoutFcn',  [], ...
    'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
end

% 初始化函数
function search_user_gui_OpeningFcn(hObject, eventdata, handles, varargin)

set(handles.figure1, 'Name', '汽修零件查询');
axis equal off;

handles.rootDirectory = pwd;

handles.output = hObject;
guidata(hObject, handles);
end

function varargout = search_user_gui_OutputFcn(hObject, eventdata, handles)

varargout{1} = handles.output;
end

% 输入框接收到回车时执行的函数
function edit_Callback(hObject, eventdata, handles)
pushbutton_Callback(hObject, eventdata, handles);
end
        
% GUI 程序需要的函数
function edit_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

end

% 搜索按钮被按下时执行的函数
function pushbutton_Callback(hObject, eventdata, handles)
handles.keywords = get(handles.edit, 'String');
if (strlength(handles.keywords) == 0)                   
    set(handles.edit,'String','PC56推土铲总成');
    handles.keywords = 'PC56推土铲总成';
end
guidata(hObject, handles);
handles = UpdateModelMatrix(hObject, handles, handles.rootDirectory);
end

% 型号下拉栏的值被改变时执行的函数
function popupmenu_model_Callback(hObject, eventdata, handles)
handles.userChoice(1) = get(hObject, 'Value');
handles = UpdateModelDirectory(hObject, handles);
guidata(hObject, handles);
end

function popupmenu_model_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
end

% 零件下拉栏的值被改变时执行的函数
function popupmenu_information_Callback(hObject, eventdata, handles)
handles.userChoice(2) = get(hObject, 'Value');
handles = UpdateNumberMatrix(hObject, handles);
guidata(hObject, handles);
end

function popupmenu_information_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
end

% 序号下拉栏的值被改变时执行的函数
function popupmenu_number_Callback(hObject, eventdata, handles)
handles.userChoice(3) = get(hObject, 'Value');
printInformation(hObject, handles);
guidata(hObject, handles);
end

function popupmenu_number_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
end

% 将 str 输出到 GUI 的文本窗口
function GUIprintf(hObject, handles, str)
if(isstring(str) && length(str) > 1)
    str1 = str;
    str = "";
    for i = str1
        str = str + "\n" + i;
    end
end
set(handles.text, 'String', sprintf(str));
guidata(hObject, handles);
end

% 列出给定目录下的文件/夹 名组成的 string 数组（列向量）
% 如果 onlydir 为 true，只返回文件夹
function fileArray = ListDirectory(path, onlydir)
listing = dir(path);
fileArray = strings(size(listing));
fileArray(:) =  {listing.name};
if (onlydir)
    fileArray = fileArray([listing.isdir]);
end
% 删除 . 开头的文件/文件夹
fileArray(startsWith(fileArray(:),'.')) = [];
end

% 输入主串数组和关键字串，输出匹配度函数值（降序排列）及在主串数组的下标
function [score, index] = MatchString(strArray, pattern)
cpattern = char(pattern);
scoreMax = 50;
score = zeros(1,scoreMax);
index = zeros(1,scoreMax);
f = @(l,k) l.^2 * (2 - 2.^(1-k));
for t = 1:length(strArray)
    score1 = 0;
    for i = 1:strlength(cpattern)
        for j = i:strlength(cpattern)
            k = length(strfind(strArray(t),cpattern(i:j)));
            l = j - i + 1;
            score1 = score1 + f(l,k);
        end
    end
    if (score1 > score(scoreMax))
        score(scoreMax) = score1;
        index(scoreMax) = t;
        [score, idx] = sort(score,'descend');
        index = index(idx);
    end
end
score = score(score>0);
index = index(index>0);
end

% 更新型号信息矩阵
function handles = UpdateModelMatrix(hObject, handles, path)
manufacturerString = ListDirectory(path, true);
handles.modelMatrix = [];
for manufacturerString1 = manufacturerString'
    modelString = ListDirectory(char(path + "\" + manufacturerString1), true);
    manufacturerString111 = strings(size(modelString));
    manufacturerString111(:) = manufacturerString1;
    manufacturerModelString = manufacturerString111 +  modelString;
    handles.modelMatrix = [handles.modelMatrix;
        manufacturerString111, modelString, manufacturerModelString];
end

[score, index] = MatchString(handles.modelMatrix(:,3), handles.keywords);
if (isempty(score))
    GUIprintf(hObject, handles, '\n\n\n没有匹配到厂家型号，可能输入有误，请重新输入')
    cla;
    return;
end
handles.modelRanking.score = score;
handles.modelRanking.index = index;

handles.userChoice(1) = 1;
set(handles.popupmenu_model, 'String',handles.modelMatrix(index,3));
guidata(hObject, handles);
handles = UpdateModelDirectory(hObject, handles);
end

% 更新型号的文件夹
function handles = UpdateModelDirectory(hObject, handles)
modelIndex = handles.modelRanking.index(handles.userChoice(1));
GetModelDirectory = @(x) handles.rootDirectory + "\" + x(1) + "\" + x(2);
handles.modelDirectory = GetModelDirectory(handles.modelMatrix(modelIndex,:));
handles = UpdateIndexMatrix(hObject, handles);
handles = UpdateInformationMatrix(hObject, handles);
guidata(hObject, handles);
end

% 更新目录信息矩阵
function handles = UpdateIndexMatrix(hObject, handles)
indexFile = handles.modelDirectory + "\index.xlsx";
if(~exist(indexFile,'file'))
    GUIprintf(hObject, handles, '\n\n\n该型号的目录文件不存在，请重新选择');
    return;
end
handles.indexMatrix = readmatrix(indexFile,"OutputType",'string','NumHeaderLines',1);
handles.indexMatrix = handles.indexMatrix(:, [1 2 4 6 7]);

% 设置页码到器件名/下标的映射，加速搜索
name = handles.indexMatrix(:,2) + "-" + handles.indexMatrix(:,3);
handles.Map_page_name = containers.Map(handles.indexMatrix(:,5), name);
handles.Map_page_idx = containers.Map(handles.indexMatrix(:,5), 1:size(handles.indexMatrix));
guidata(hObject, handles);
end

% 更新零件信息矩阵
function handles = UpdateInformationMatrix(hObject, handles)
informationFile = handles.modelDirectory + "\table.xlsx";
if(~exist(informationFile,'file'))
    GUIprintf(hObject, handles, '\n\n\n该型号的零件信息文件不存在，请重新选择');
    cla;
    return;
else
    hello = 1;
end
informationMatrix = readmatrix(informationFile,"OutputType",'string','NumHeaderLines',1);
informationMatrix(:,7) = string;
for i = 1 : size(informationMatrix)
    informationMatrix(i,7) = handles.Map_page_name(char(informationMatrix(i,1))) + "-" ...
        + informationMatrix(i,4);
end

handles.informationMatrix = informationMatrix;

[score, index] = MatchString(informationMatrix(:,7),handles.keywords);
if (isempty(score))
    GUIprintf(hObject, handles, '该厂商下没有匹配到零件，可能输入有误，请重新输入或选择厂商');
    cla;
    guidata(hObject, handles);
    return;
end

% 下面将进行名字的去重、合并
indexCell = {};
i = 1;
SameName = @(x,y) informationMatrix(x,7) == informationMatrix(y,7);
while (i <= length(index))
    indexCell{i} = index(i);
    j = i + 1;
    while(j <= length(index) && score(j) == score(i))
        if (SameName(index(i), index(j)))
            indexCell{i} = [indexCell{i}, index(j)];
            score(j) = [];
            index(j) = [];
        else
            j = j + 1;
        end
    end
    i = i + 1;
end

handles.informationRanking.score = score;
handles.informationRanking.indexCell = indexCell;
handles.userChoice(2) = 1;
set(handles.popupmenu_information, 'String',handles.informationMatrix(index,7));
handles = UpdateNumberMatrix(hObject, handles);
guidata(hObject, handles);
end

% 更新用户选择的零件的下标
function handles = UpdateNumberMatrix(hObject, handles)
currentIndexMatrix = handles.informationRanking.indexCell{handles.userChoice(2)};
numberMatrix = zeros(size(currentIndexMatrix));
for i = 1:length(numberMatrix)
    numberMatrix(i) = handles.informationMatrix(currentIndexMatrix(i),2);
end
set(handles.popupmenu_number, 'String',numberMatrix);
handles.userChoice(3) = 1;
printInformation(hObject, handles);
guidata(hObject, handles);
end

% 输出用户选定的零件的图文信息
function printInformation(hObject, handles)
currentModel = handles.modelRanking.index(handles.userChoice(1));
currentIndexCell = handles.informationRanking.indexCell{handles.userChoice(2)};
currentInformation = currentIndexCell(handles.userChoice(3));
currentComponent = handles.Map_page_idx(handles.informationMatrix(currentInformation,1));

infoString = [ handles.modelMatrix(currentModel, 1:2) ...
    handles.indexMatrix(currentComponent, 2:3) ...
    handles.informationMatrix(currentInformation,2:6)];
explainString = ["\n厂商" "型号"...
    "器件" "部件" ...
    "图中序号" "件号" "零件" "数量" "系列号"];
GUIprintf(hObject, handles, explainString  + "：" +infoString);

fig_name = handles.indexMatrix(currentComponent, 4);
fig = imread(handles.modelDirectory + "\graph\" + fig_name + ".png");
image(fig);
axis equal off;

guidata(hObject, handles);
end
