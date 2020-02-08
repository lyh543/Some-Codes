#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;

const int size = 20;

int main()
{
	int n = 0;
	int height[size];
	int longest[size] = {0}; //如果强行接第i发子弹，那么前i发导弹中最多可以拦多少 
	
	while (cin >> height[n])
		n++;
	
	for (int i = 0; i < n; i++)
	{
		int max = 0;
		for (int j = 0; j < i; j++)
		{
			if (height[j] > height[i] && longest[j] > max)
				max = longest[j]; 
		}
		
		longest[i] = max + 1;
	}
	
	int l = 0;
	for (int i = 0; i < n; i++) {if (l < longest[i]) l = longest[i]; } 
	cout << l << endl;
	
	int sys[size] = {0};
	int sys_n = 0;
	
	for (int i = 0; i < n; i++)
	{
		int * min_p = NULL;
		for (int j = 0; j < sys_n; j++)
		{
			if (sys[j] > height[i] && (min_p == NULL || *min_p > sys[j]))
				min_p = &sys[j];
		}
		
		if (min_p == NULL)
		{
			sys[sys_n] = height[i];
			sys_n++;
		}
		else
		{
			*min_p = height[i];
		}
	}
	
	cout << sys_n;
	
}
