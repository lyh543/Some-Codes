#include<iostream>
#include<cstdio>

#define SIZE 1000 
using namespace std;

long long yanghui[2][SIZE];
int operateArray = 0;

int main()
{
	for (int length = 1;length <= SIZE; length++)
	{
		yanghui[operateArray][0] = 1;
		yanghui[operateArray][length - 1] = 1;
		for (int i = 1; i < length - 1; i++)
		{
			yanghui[operateArray][i] = yanghui[!operateArray][i] + yanghui[!operateArray][i - 1]; 
		}
		
		for (int i = 0; i < length; i++)
		{
			cout << yanghui[operateArray][i];
			if (i != length - 1)
				cout << '\t'; 
		}
		//cout << endl;
		getchar();
		operateArray = !operateArray;
	}
}
 
