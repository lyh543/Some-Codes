#pragma once
#include"../CmdCommand.h"

using namespace std;

//显示当前文件夹的所有子文件夹及文件
int Command_TREE(ostream& out, const vector<string>& argument);

class fileTreeNodeClass //文件的结构是一棵树，用孩子表示法进行存储
{
public:
	string fileName;
	long long fileSize; //如果是文件夹，则是其下的所有文件的大小
	vector<fileTreeNodeClass*> sonList; //子节点
	fileTreeNodeClass() : fileSize(0){}
	~fileTreeNodeClass() //删除整棵树直接调用根结点的析构函数就行了
	{
		for (fileTreeNodeClass* son : sonList)
			delete son;
	}
	void addSon(fileTreeNodeClass * sonNode)
	{
		sonList.push_back(sonNode);
	}
};

class fileTreeClass
{
public:
	fileTreeNodeClass* root;
	fileTreeClass() : root(new fileTreeNodeClass){}
	~fileTreeClass()
	{
		delete root;
	};
};


