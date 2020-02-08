#include<iostream>
#include<queue>
 
using namespace std;

struct BIG_NUM{
	long long v;
};

int operator < (const BIG_NUM& a, const BIG_NUM& b)
{
	return a.v > b.v;
} 

BIG_NUM combine(BIG_NUM a, BIG_NUM b)
{
	BIG_NUM x;
	x.v = a.v*b.v+1;
	return x;
}

int main()
{
	int n;
	BIG_NUM a,b,t;
	t.v = 1;
	priority_queue<BIG_NUM> array;
	cin >> n;
	for (int i = 0; i < n; i++)
		array.push(t);
	
	while (array.size() != 1)
	{
		a = array.top();
		array.pop();
		b = array.top();
		array.pop();
		
		array.push(combine(a,b));
	}
	cout << array.top().v;
}
