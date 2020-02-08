#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cctype>
#include<string>
#include<cassert>
#include<algorithm>
#include<stack>

using namespace std;

const int INF = 0x3f3f3f3f, maxCity = 1000, maxLength = 1000;

int dist[maxCity][maxCity], path[maxCity][maxCity];

char getChoice()
{
	char tempstr[1000];
	char choice;
	for (;;)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> tempstr;
		choice = tolower(tempstr[0]);
		if (choice == 'y' || choice == 'n')
			break;
		cout << "输入错误，请重新输入。(y/n)";
	}
	return choice;
}

string getPath(int a, int b)
{
	if (path[a][b] == INF)
		return "";
	
	char str[10];
	sprintf_s(str,10, " %d ", path[a][b]);
	return getPath(a, path[a][b]) + str + getPath(path[a][b], b);
}

int main()
{
	int city, road;
	for (;;)
	{
		cout << "请输入城市数、（双向）道路数：\n";
		cin >> city >> road;
		if (city <= 0)
			cout << "城市数需要大于 0。请重新输入\n";
		else if (city > maxCity)
			cout << "城市数需要小于 " << maxCity << "，请重新输入。\n";
		else if (road < 0)
			cout << "道路数需要大于 0。请重新输入。\n";
		else if (road > city* (city - 1) / 2)
			cout << "城市数需要小于 " << city * (city - 1) / 2 << "，请重新输入。\n";
		else
			break;
	}

	memset(dist, 0x3f, sizeof(dist));
	memset(path, 0x3f, sizeof(path));

	cout << "需要生成随机线路吗？ 如需要，请输入 y；否则输入 n，然后手动输入。(y/n)";

	if (getChoice() == 'y')
	{
		vector<pair<int, int> > sequence; //包含所有边的序列
		for (int i = 0; i < city; i++)
			for (int j = i + 1; j < city; j++)
				sequence.push_back({ i,j });

		for (int i = 1; i < sequence.size(); i++)
			swap(sequence[i], sequence[rand() % sequence.size()]); //使用 Fisher–Yates Shuffle Algorithm 将其变为随机序列

		for (int i = 0; i < road; i++) //取前 road 条边则得到了随机的 road 条边
			dist[sequence[i].first][sequence[i].second] = dist[sequence[i].second][sequence[i].first] = rand() % maxLength;
	}
	else
	{
		cout << "下面请输入 " << road << " 行，每一行三个数字，分别代表道路的两个端点 和 长度：\n";
		int Inputted = 0;
		while (Inputted != road)
		{
			int a, b, l;
			cin >> a >> b >> l;
			if (cin.fail() || a < 0 || b < 0 || l < 0 || a >= city || b >= city)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "上一行输入不合法，请重新输入上一行\n";
			}
			else
			{
				dist[a][b] = dist[b][a] = l;
				Inputted++;
			}
		}
	}

	cout << "生成完毕。是否显示生成图的矩阵？（y/n）";

	if (getChoice() == 'y')
	{
		cout << "生成图的矩阵为：\n";
		for (int i = 0; i < city; i++)
		{
			for (int j = 0; j < city; j++)
			{
				if (dist[i][j] == INF)
					cout << "INF\t";
				else
					cout << dist[i][j] << "\t";
			}
			cout << "\n";
		}
		cout << endl;
	}

	for (int k = 0; k < city; k++)
		for (int i = 0; i < city; i++)
			for (int j = 0; j < city; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j], path[i][j] = k;

	cout << "已计算完任意两点间的最短路。是否显示最短路的矩阵？（y/n）";

	if (getChoice() == 'y')
	{
		cout << "最短路的矩阵为：\n";
		for (int i = 0; i < city; i++)
		{
			for (int j = 0; j < city; j++)
			{
				if (dist[i][j] == INF)
					cout << "INF\t";
				else
					cout << dist[i][j] << "\t";
			}
			cout << "\n";
		}
		cout << endl;
	}


	for (;;)
	{
		cout << "请输入两点的标号：（0-" << city-1 << "）";

		int a, b;
		cin >> a >> b;

		if (dist[a][b] == INF)
			cout << a << " 到 " << b << " 之间没有通路。";
		else
			cout << a << " 到 " << b << " 之间的距离为：" << dist[a][b] << "，路径为：" << a << " " << getPath(a, b) << " " << b << endl;

		cout << endl;
	}
	return 0;
}