#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

struct nodes{
	int data;
	int next;
}node[100];

int head = -1;
int tail = 0;

void printList()
{
	int current = head;
	while (current != -1)
	{
		cout << node[current].data << " ";
		current = node[current].next;
	}
}

void insertFirst(int data)
{
	int link = tail;
	tail++;
	
	node[link].data = data;
	node[link].next = head;
	
	head = link;
}

bool isEmpty()
{
	return head == -1; 
}

void deleteNode(int p)
{
	if (isEmpty()) return;
	
	if (head == p) //如果n就是第一个
	{
		head = node[head].next;
		node[p].next = -1;
	}
	else //如果n不是第一个，要先找到n的前一个 
	{
		int current = head;
		while (node[current].next != p)
		{
			current = node[current].next;
		}
		node[current].next = node[p].next;
		node[p].next = -1;
	}
	return;
}

int length()
{
	return tail;
}

int find(int data)
{
	int current = head;
	while (current != -1)
	{
		if (node[current].data == data) return current;
		current = node[current].next;
	}
	return -1;
}

void reverse()
{
	int current = head;
	int next = node[current].next;
	node[current].next = -1; //对第一个节点进行反转 
	int previous;
	
	while (next != -1)
	{
		previous = current;
		current = next;
		next = node[current].next;
		node[current].next = previous;
	}
	
	head = current;
}


int main()
{
	//freopen("debug.txt","w",stdout);
	
	int array[5] = {1,3,4,2,5};
	for (int i = 0; i < 5; i++)
		insertFirst(array[i]);
	
	cout << "Original List: ";
	printList();
	
	cout << "\nNow the reversed List:";
	reverse();
	printList();
	
	cout << "\nNow the sorted List:";
	sort();
	printList();
}
