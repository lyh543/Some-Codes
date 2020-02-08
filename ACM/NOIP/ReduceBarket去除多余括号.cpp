#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

const int ssize = 100;

bool reduceBarket(char * s,int l,int r)
{
	char lop = '\0', rop, op;
	if (l != 0) lop = s[l-1];
	rop = s[r+1];
	if (lop == '/') return 1; // 形如/(s1 op s2) 
	int k = 0,i;
	for (i = l; i < r; i++)
	{
		if (s[i] == '+' || s[i] == '-')
		{
			k = 0;
			break;
		}
		if (k == 0 && (s[i] == '*' || s[i] == '/'))
			k = i;
	} //若有+-，k=0，否则k指向第一个op 
	if (k == 0) op = s[i]; else op = s[k];
	if ((lop == '*' || lop == '-') && (op == '+' || op == '-')) return 1;
	if ((op == '+' || op == '-') && rop == '*') return 1;
	return 0;
}

int main()
{
	char s[ssize];
	stack<int> st;
	cin >> s;
	int i = 0;
	int l = strlen(s);
	
	for (int i = 0; i < l; i++)
	{
		if (s[i] == '(') st.push(i);
		else if (s[i] == ')')
		{
			int j = st.top();
			st.pop();
			bool t = reduceBarket(s,j,i);
			if (t == 1)
			{
				s[j] = '#';
				s[i] = '$';
			}
		}
	}
	cout << "Source:" << s << endl; 
	for (int i = 0; i < l; i++)
		switch(s[i])
		{
			case '(':
			case ')':break;
			case '#':cout << "(";break;
			case '$':cout << ")";break;
			default :cout << s[i];break;
		}
}
