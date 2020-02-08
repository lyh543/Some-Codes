#include<iostream>

using namespace std;

int  findrt(int x,int* person)
{
	int root=x,next;
	while(person[root]!=root)
		root=person[root];
	while(person[x]!=root)
	{
		next=person[x];
		person[x]=root;
		x=next;
	}
	return root;
}

void adjust(int root, int x);

int main()
{
	int m,n,p,i,rela1,rela2,j;
	cin >> n >> m >> p; //n个人，m个关系，问p个关系 
	int person[n];
	char judge[p];
	p--;
	for (i=0;i<n;i++) //将数组标号为n的人设为n 
		person[i]=i;	
	for (i=1;i<=m;i++)
	{
		cin >> rela1 >> rela2;
//cout << "Input:" << rela1 << " " << rela2 << "\tArray:";
		rela1--;
		rela2--;
/*		if (person[rela1]==rela1)
			person[rela2]=rela1;
		else if (person[rela2]==rela2)
			person[rela1]=rela2;
		else
			person[rela2]=findrt(rela1,person);
*/
		person[findrt(rela1,person)]=findrt(rela2,person);
//cout << "Array:";
//for (j=0;j<n;j++)
//cout << person[j] << " ";
//cout << endl;
	}
	
	for (i=0;i<=p;i++)				
	{
		cin >> rela1 >> rela2;
		rela1--;
		rela2--;
		judge[i]=(findrt(rela1,person)==findrt(rela2,person));
	}
	for (i=0;i<=p;i ++)
	{
		if (judge[i]==0)
			cout << "No";
		else
			cout << "Yes";
		if (i!=p)
			cout << endl;
	}
}
