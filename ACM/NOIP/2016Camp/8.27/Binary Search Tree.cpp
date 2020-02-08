#include<iostream>
#include<cstdlib>

using namespace std;

struct node{
	int data;
	node * left;
	node * right;
};

node * root = NULL;

void insert(int data)
{
	node * temp = (node*)malloc(sizeof(node));
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;
	
	if (root == NULL)
	{
		root = temp;
		return;
	}
	node * parent = root;
	
	while(true)
	{
		if (temp -> data >= parent -> data)
		{
			if (parent -> right == NULL)
			{
				parent -> right = temp;
				return;
			}
			else
			{
				parent = parent -> right;
			}
		}
		else
		{
			if (parent -> left == NULL)
			{
				parent -> left = temp;
				return;
			}
			else
			{
				parent = parent -> left;
			}
		}
	}
	
}

int main()
{
	int array[10] = {1,5,0,2,6,3,8,9,7,4};
	for (int i = 0; i < 10; i++)
	{
		insert(array[i]);
	}
	
}
