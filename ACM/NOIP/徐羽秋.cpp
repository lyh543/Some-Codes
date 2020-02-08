#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;

const int n_space = 2000; // n的范围 
const int name_space = 101; //班级名称长度的范围 

int m, people;
double highest = 0;
double average[n_space];
char highest_classname[name_space],classname[name_space];

int main()
{
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		double sum = 0;
		cin >> people >> classname;
		
		for (int j = 0; j < people; j++)
		{
			double height;
			cin >> height;
			sum = sum + height;
		}
		average[i] = sum / people;
		
		if (average[i] > highest)
		{
			highest = average[i];
			strcpy(highest_classname, classname);
		}
	}
	
	cout << highest_classname << endl;
	cout << setiosflags(ios::fixed) << setprecision(2);
	for (int i = 0; i < m; i++)
	{
		cout << average[i] << endl;
	}
}
