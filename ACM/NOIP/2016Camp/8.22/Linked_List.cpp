#include<iostream>
#include<cstdlib>

using namespace std;

struct node{
	int data;
	struct node* next;
};

node* head = NULL;

void printList()
{
	node* current = head;
	while (current != NULL)
	{
		cout << current->data << " ";
		current = current->next;
	}	
}

void insertFirst(int data)
{
	node* link = (node*) malloc(sizeof(node));
	
	link->data = data;
	link->next = head;
	
	head = link;
}

bool isEmpty()
{
	return head == NULL; 
}

void deleteNode(node* n)
{
	if (isEmpty()) return;
	
	if (head == n) //如果n就是第一个
	{
		head = head->next;
		n->next = NULL;
	}
	else //如果n不是第一个，要先找到n的前一个 
	{
		node* current = head;
		while (current->next != n)
		{
			current = current->next;
		}
		current->next = n->next;
		n->next = NULL;
	}
	
	return;
}

void deleteNode(int data)
{
	if (isEmpty()) return;
	
	if (head->data == data) //如果n就是第一个
	{
		node* n = head;
		head = head->next;
		n->next = NULL;
	}
	else //如果n不是第一个，要先找到n的前一个 
	{
		node* current = head;
		while (current->next->data != data)
		{
			current = current->next;
		}
		node* n = current->next;
		current->next = n->next;
		n->next = NULL;
	}
}

int length()
{
	int l = 0;
	node * pt = head;
	while (pt != NULL)
	{
		l++;
		pt = pt->next;
	}
	return l;
}

node* find(int data)
{
	node* current = head;
	while (current != NULL)
	{
		if (current->data == data) return current;
		current = current->next;
	}
	return NULL;
}

void reverse()
{
	node* current = head;
	node* next = current->next;
	current->next = NULL; //对第一个节点进行反转 
	node* previous;
	
	while (next != NULL)
	{
		previous = current;
		current = next;
		next = current->next;
		current->next = previous;
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
}
