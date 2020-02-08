//The first floor is contributed to t123yh and his OS code
//The second floor is contributed to Huang StudyLong and his ladies 

#include<cstdio>

using namespace std;
const int tsize = 15000010;

long long  girl[tsize] = {0};
long long  n, cur=0, maxn=0, maxt; 

int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		long long come, go;
		scanf("%d%d",&come,&go);
		if (maxt < ++go) maxt = go;
		girl[come]++; //one meiza comes 
		girl[go]--; //one meiza goes
	}
	
	for (int i = 0; i <= maxt; i++)
	{
		cur += girl[i];
		if (maxn < cur) maxn = cur;
	}
	
	printf("%d",maxn);
}
