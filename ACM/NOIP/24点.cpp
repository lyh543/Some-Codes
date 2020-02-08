#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> ans[4][4];//ans[i][j]指从i到j的可能的值，0<=i,j<=3
bool isInVector[50];
int n=0;
string s;
bool out = false;

void pushIn(int,vector<int>&);



int main()
{
	freopen("input.txt", "r", stdin);
	
	//有趣的输入
	while (cin >> s && n!=4)
	{
		if (s == " ")
			continue;
		else if (s[0] == 'A' || s[0] == 'a')
			ans[n][n].push_back(1);
		else if (s == "10")
				ans[n][n].push_back(10);
		else if (s[0] == 'J' || s[0] == 'j')
			ans[n][n].push_back(11);
		else if (s[0] == 'Q' || s[0] == 'q')
			ans[n][n].push_back(12);
		else if (s[0] == 'K' || s[0] == 'k')
			ans[n][n].push_back(13);
		else
			ans[n][n].push_back(s[0] - 48);
		n++;
	}
	//有趣的输入完成

	for (int dis = 1; dis < 4; dis++) //dis指i到j的距离
	{
		for (int i = 0; i + dis < 4; i++)
		{
			int j = i + dis;
			for (int point = i; point < j; point++)
			{
				//memset(isInVector, false, sizeof(isInVector));
				for (int x = 0; x < sizeof(isInVector); x++)
					isInVector[x]=false; 
				for (vector<int>::iterator element_i = ans[i][point].begin(); element_i < ans[i][point].end(); element_i++)
					for (vector<int>::iterator element_point = ans[point+1][j].begin(); element_point < ans[point+1][j].end(); element_point++)
					{//将每合并两数可能的所有值push进对应的vector中
						pushIn(*element_i + *element_point, ans[i][j]);
						pushIn(*element_i - *element_point, ans[i][j]);
						pushIn(*element_i * *element_point, ans[i][j]);
						if (*element_point != 0 && *element_i % *element_point == 0)
							pushIn(*element_i / *element_point, ans[i][j]);
					}
			}
		}
	}
	for (vector<int>::iterator i = ans[0][3].begin(); i < ans[0][3].end(); i++)
		if (*i == 24)
		{
			out = true;
			break;
		}
	if (out)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}

void pushIn(int n,vector<int>& v)
{
	if (n>=sizeof(isInVector))
	{
		v.push_back(n);
	}
	else if (!isInVector[n])
	{
		v.push_back(n);
		isInVector[n] = true;
	}
}

