#include<iostream>
#include<cstdio>

//#define debug

using namespace std;

int main()
{
#ifndef debug
	freopen("choco.in", "r", stdin);
	freopen("choco.out", "w", stdout);
#endif

	int a, b, n;
	while (scanf("%d%d%d", &n, &a, &b) != EOF)
	{
		printf("%d\n", n%(a+b) >= a);
	}

#ifndef debug
	fclose(stdin);
	fclose(stdout);
#endif
}
