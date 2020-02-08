#include<iostream>
#include<list>  //垃圾list::erase，毁我青春 

using namespace std;

const int nodeSize = 300010;
int n, t, maxnum = 0;

list<int> l;

void erase(list<int>::iterator &iter)
{
	list<int>::iterator iter2 = iter;
	iter2++;
	l.erase(iter);
	iter = iter2;
} 

int length2 (long long numb)//得到n的位数
{
	int length = 0;
	for (int i = 32; i > 0; i >>= 1)
	{
		//cout << (numb>>32);
		if ((numb>>i) != 0)
		{
			length += i;
			numb >>= i;
		}
	}
	return length+1;
}

int simplify(list<int>::iterator t1, list<int>::iterator t2, int base)
{
	l.erase(l.begin(), t1);
	
	list<int>::iterator p = t1;
	p++; // skip t2
	l.erase(p,t2);
	
	p = t2;
	while (p != l.end())
	{
		if (((*p >> base) & 1))
			p++;
		else
		{
			erase(p);
		}
	}
}

void printAns()
{
	list<int>::iterator iter1, iter2;
	iter1 = iter2 = l.begin();
	iter2++;
	cout << ((*iter1) & (*iter2));
	return;
}

int main()
{		
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		l.push_back(num);
		if (maxnum < num) maxnum = num;
	}
	
	for (int length = length2(maxnum)-1; length >= 0; length--)
	{
		bool OK1 = false; //是否已经有一个数的l+1位是1
		list<int>::iterator save; 
		for (list<int>::iterator iter = l.begin(); iter != l.end(); iter++)
		{
			if ((*iter >> length) & 1)
			{
				if (OK1 == true)
				{
					simplify(save, iter, length);
					if (l.size() == 2)
					{
						printAns();
						return 0;
					}
				}
				else
				{
					OK1 = true;
					save = iter;
				}
			}
		}
	}
	printAns();
	return 0;
}
