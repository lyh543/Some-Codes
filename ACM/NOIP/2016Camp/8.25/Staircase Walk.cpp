#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

const int size = 10, barrier_n = 10;
int matrix[size][size] = {0};

int main()
{
	srand(time(NULL));
	
	for (int i = 0; i < barrier_n; i++)
	{
		int a, b;
		do
		{
			a = rand() % size;
			b = rand() % size;
		}
		while (a != 0 && b!= 0);
		matrix[a][b] = -1; //-1±íÊ¾ÓÐÕÏ°­
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrix[i][j] == -1)
			{
				matrix[i][j] = 0;
				continue;
			}
			
			if (i == 0)
			{
				matrix[i][j] = 1;
			}
			
			else
			{
				matrix[i][j] = matrix[i-1][j];
			}
			
			if (j != 0)
			{
				matrix[i][j] += matrix[i][j-1];
			}
		}
		
		for (int j = 0; j < size; j++)
			cout << matrix[i][j] << "	";
		cout << endl;
	}
	
}
