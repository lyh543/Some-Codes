//一楼献学长 
//暴力，能过几个过几个 
#include<iostream>
#include<queue>

using namespace std; 
const int size = 50010;

int stone[size] = {0};
int del, n;

struct neighborStruct{
	int dis;   //distance between 2 points
	int front; //the number of the front point
}t;

bool operator < (const neighborStruct a, const neighborStruct b)
{
	return a.dis > b.dis;
}

priority_queue<neighborStruct> neigh;

int main()
{
	//freopen("input.txt","r",stdin);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> stone[0];
	cin >> n;
	n += 2;
	stone[n-1] = stone[0];
	stone[0] = 0;
	cin >> del;
	for (int i = 1; i < n-1; i++)
	{
		cin >> stone[i];
		t.dis = stone[i] - stone[i-1];
		t.front = i-1;
		neigh.push(t);
	}
	t.dis = stone[n-1] - stone[n-2];
	t.front = n-2;
	neigh.push(t);
	
	int time = del;
	while (time > 0 && !neigh.empty())
	{
		t = neigh.top(); neigh.pop();
		int p = t.front;
		//cout << p; 
		if (stone[p] == -1 || stone[p+1] == -1)
			continue; //The stone is already moved
		
		if (p == 0) p++; 
		else if (p+1 != n && stone[p+1] - stone[p-1] > stone[p+2] - stone[p])
			p++;
		//Then we need to move the "p". Just greedy.
		stone[p] = -1;
		
		int l = p-1, r = p+1;
		while (stone[l] == -1) l--;
		while (stone[r] == -1) r++;
		t.front = l;
		t.dis = stone[r] -stone[l];
		neigh.push(t);
		time--;
	}
	
	cout << "";
	do 
	{
		//cout << "Int";
		t = neigh.top();neigh.pop();
		//cout << "eresting";
	}
	while (stone[t.front] == -1 || stone[t.front+1] == -1);
	
	cout << t.dis;
}
