#include<iostream>
#include<list>
//#define debug

using namespace std;

const int size = 200005;

int n, maxi = 0;
long long ans = 0;
int weight[size];
list<int> connect[size];//以某个点作为

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef debug
	freopen("input.txt","r",stdin);
#endif

	cin >> n;
	int a, b;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		connect[a].push_back(b);
		connect[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> weight[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		int max1 = 0, max2 = 0, sum = 0;
		for (list<int>::iterator iter = connect[i].begin(); iter != connect[i].end(); iter++)
		{
			//get maximum across this point
			if (weight[*iter] > max1)
			{
				max2 = max1;
				max1 = weight[*iter];
			}
			else if (weight[*iter] > max2)
			{
				max2 = weight[*iter];
			}
			
			sum = (sum + weight[*iter]) % 10007; 
		}
		max1 *= max2;
		if (max1 > maxi) maxi = max1;
		
		
		//get sum across this point
		for (list<int>::iterator iter = connect[i].begin(); iter != connect[i].end(); iter++)
		{
			//int t = (sum - weight[*iter]) * weight[*iter];
			ans = (ans + ( sum - weight[*iter] ) * weight[*iter]) % 10007;
			//cout << t << " " << ans << endl;
		}
	}
	
	cout << maxi << " " << ans;
}
