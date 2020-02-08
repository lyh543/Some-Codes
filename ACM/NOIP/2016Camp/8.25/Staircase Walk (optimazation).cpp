#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stack>

using namespace std;

const int size = 10;

struct point{
	int x;
	int y;
};

struct square
{
	int max;
	int way;
	//stack<point> path;
};

int main()
{
	square matrix[size][size];
	int condition[size][size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			cin >> condition[i][j];
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j].max = condition[i][j];
			if (i == 0 & j == 0)
			{
				matrix[i][j].way = 1;
				continue;
			}
			else if (i == 0 || matrix[i][j-1].max > matrix[i-1][j].max)
			{
				matrix[i][j].way = matrix[i][j-1].way;
				matrix[i][j].max += matrix[i][j-1].max;
				continue;
			}
			else if (j == 0 || matrix[i][j-1].max < matrix[i-1][j].max)
			{
				matrix[i][j].way = matrix[i-1][j].way;
				matrix[i][j].max += matrix[i-1][j].max;
				continue;
			}
			else
			{
				matrix[i][j].way = matrix[i-1][j].way + matrix[i][j-1].way;
				matrix[i][j].max += matrix[i-1][j].max;
			}
		}
	}

	cout << "Maximum: " << matrix[size-1][size-1].max << endl
		 << "There are " << matrix[size-1][size-1].way << " way(s)";
}

/*test data:
3 1 4 2 5 4 0 1 2 1
2 2 2 0 3 2 4 3 3 1
0 4 4 5 5 4 4 2 4 2
3 4 0 3 5 5 0 2 3 1
1 3 2 3 5 3 4 1 5 4
5 5 5 5 3 2 4 3 5 4
4 3 2 5 0 1 3 3 1 4
3 3 3 0 3 1 2 4 3 2
4 2 4 1 1 1 0 4 3 1
5 5 0 1 3 2 2 1 2 2
*/
