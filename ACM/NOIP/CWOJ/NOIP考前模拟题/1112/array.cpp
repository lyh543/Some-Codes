#include<iostream>
#include<climits>

using namespace std;

const int arraySize = 55, numSize = 5010, orderSize = 250010, inf = 10000000;
struct arrayStruct{
	int value[numSize];
	int length;
	int sum;
	int lmax; //max sum from left
	int rmax; //max sum from right
	//int imax; //max sum inside
}array[arraySize];

int arrayN, numN, orderN;
int maxInside = -inf; // maybe the max is simply in 1 array

int main()
{
	//freopen("input.txt", "r", stdin);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> arrayN >> orderN;
	for (int i = 0; i < arrayN; i++) // get and process arrays
	{
		cin >> array[i].length;
		cin >> array[i].value[0];
		int sum, sumMax, sumMin, sumIn, maxIn;
		sum = sumMax = sumMin = sumIn = maxIn = array[i].value[0];
		if (sumMin > 0) sumMin = 0;
		for (int j = 1; j < array[i].length; j++)
		{
			cin >> array[i].value[j];
			sum += array[i].value[j];
			if (sum > sumMax) sumMax = sum;
			else if (sum < sumMin) sumMin = sum;
			
			if (sumIn < 0) sumIn = array[i].value[j];
			else sumIn += array[i].value[j];
			if (sumIn > maxIn) maxIn = sumIn;
		}
		array[i].sum = sum;
		array[i].lmax = sumMax;
		array[i].rmax = sum - sumMin;
		if (maxInside < maxIn) maxInside = maxIn;
		
	}
	
	int order;
	cin >> order; order--;
	long long maxhere = array[order].rmax; // now the max sum(use sum instead of rmax in the last)
	long long ans = maxInside; //maybe just the ans
	for (int i = 1; i < orderN; i++)
	{
		cin >> order; order--;
		if (maxhere < 0) maxhere = array[order].lmax;
		else 
		{
			if (maxhere + array[order].lmax > ans) ans = maxhere + array[order].lmax;
			maxhere += array[order].sum;
		}
	}
	
	cout << ans;
}

