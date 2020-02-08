#include<iostream>

using namespace std;

const int arraySize = 55, numSize = 5010, orderSize = 250010, inf = 10000000;
int array[arraySize][numSize];
int arrayL[arraySize];

int arrayN, numN, orderN;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> arrayN >> orderN;
	for (int i = 0; i < arrayN; i++) // get and process arrays
	{
		cin >> arrayL[i];
		for (int j = 0; j < arrayL[i]; j++)
			cin >> array[i][j];
	}
	
	int order;
	long long max = 0, maxNow = 0;
	for (int i = 0; i < orderN; i++)
	{
		cin >> order; order--;
		for (int j = 0; j < arrayL[order]; j++)
		{
			if (maxNow < 0) maxNow = 0;
			else
			{
				maxNow += array[order][j];
				if (maxNow > max) max = maxNow;
			}
		}
	}
	
	cout << max;
}

