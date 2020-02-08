#include<iostream>
#include<cstdio>

using namespace std;

const int size = 1000;

long long a, b, ans = 0;

long long array[size];

bool getAns(long long n)
{
	ans++;
	array[ans] = n;
	
	if (n == a) return true;
	if (n < a)
	{
		return false;
	}
	
	if (n%2 == 0) return getAns(n/2);
	else if (n%10 == 1) return getAns(n/10);
	else return false;
}

int main()
{
	//freopen("super.in","r",stdin);
	//freopen("super.out", "w", stdout);
	
	scanf("%lld%lld", &a, &b);
	
	if (getAns(b))
	{
		printf("YES\n%lld\n", ans);
		for (int i = ans; i > 0; i--)
		{
			printf("%lld ", array[i]);
		}
	}
	else
	{
		printf("NO");
	}
	
	//fclose(stdin);
	//fclose(stdout); 
}
