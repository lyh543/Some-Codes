#include<iostream>
#include<cmath>

using namespace std;

const int heap_size = 10000;

//A[0]¼´heap_size

int parent(int i) { return i / 2; }
int left(int i) { return i * 2; }
int right(int i) { return i * 2 + 1; }
int height(int * A) { return (int)log((double)A[0]) / log(2.0); }
void Heapify(int * A, int i)
{
	int L = left(i);
	int R = right(i);
	int largest = i;
	if (L <= A[0] && A[L] > A[largest])
		largest = L;
	if (R <= A[0] && A[R] > A[largest])
		largest = R;

	if (i != largest)
	{
		swap(A[i], A[largest]);
		Heapify(A, largest);
	}
}
void Build_Heap(int * A)
{
	for (int i = A[0] / 2; i >= 1; i--)
	{
		Heapify(A, i);
	}
}
void Heap_sort(int * A)
{
	for (int i = A[0]; i > 1; i--)
	{
		swap(A[1], A[i]);
		A[0]--;
		Heapify(A, 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int A[heap_size] = { 0 };
	while (cin >> A[A[0] + 1])
		A[0]++;
	int l = A[0];

	Build_Heap(A);
	Heap_sort(A);
	for (int j = 1; j <= l; j++) cout << A[j] << " ";
	return 0;
	cout << A[0] << A[1] << A[2] << A[3] << A[4] << A[5] << A[6];
}
