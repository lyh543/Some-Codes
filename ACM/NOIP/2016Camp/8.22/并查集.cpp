#include<iostream>

int findrt(int x)
{
	while (array[x] != x)
	{
		x = array[x];
	}
	return x;
} 

int join(int a,int b)
{
	int rt = findrt(b); //½«a¹éµ½bÏÂ
	int t;
	array[findrt(a)] = rt;
	
	while (array[a] != a)
	{
		t = array[a];
		array[a] = rt;
		a = t;
	}
	while (array[b] != b)
	{
		t = array[b];
		array[b] = rt;
		b = t;
	}
	
	return rt;
}

int main()
{
	int array[1000];
	cin >> n;
	for (int i = 0; i < n; i++)
		array[i] = i;
		
	
} 
