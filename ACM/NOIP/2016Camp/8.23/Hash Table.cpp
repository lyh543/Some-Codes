#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

const int asize = 100;
const int size = 20;

struct node{
	int data;
	node * next;
};

int getHash(int n)
{
	return n % size;
}

int makeHash(int * array,node ** HashTable)
{
	for (int i = 0; i < asize; i++)
	{
		int t_hash = getHash(array[i]);
		if (HashTable[t_hash] == NULL)
		{
			HashTable[t_hash] = (node*)malloc(sizeof(node));
			HashTable[t_hash]->data = array[i];
			HashTable[t_hash]->next = NULL;
		}
		else
		{
			node * t_node = HashTable[t_hash]; 
			while (t_node->next != NULL)
			{
				t_node = t_node->next;
			}
			t_node->next = (node*)malloc(sizeof(node));
			t_node = t_node->next;
			t_node->data = array[i];
			t_node->next = NULL;
		}
	}
}

bool find(int x, int * array, node * HashTable[])
{
	node * t_node = HashTable[getHash(x)];
		while (t_node != NULL)
		{
			if (t_node->data == x)
			{
				cout << x << " Exists in Array";
				return true;
			} 
			t_node = t_node->next;
		}
	cout << x << " Doesn't Exist";
	return false;
}

int main()
{
	srand(time(NULL));
	int array[asize];
	node * HashTable[size] = {NULL};
	for (int i = 0; i < asize; i++)
	{
		array[i] = rand();
		cout << array[i] << " "; 
	}
	cout << endl << endl;
	
	makeHash(array, HashTable);
	
	find(array[89], array, HashTable);
} 
