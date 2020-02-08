#include<iostream>
#include<algorithm>

using namespace std;

struct time{
	int s; //start
	int e; //end
//	bool exist;
}mt[500]; //Meetint Time

int cmp(const void* a, const void* b)
{
	return (*(time *)a).e > (*(time *)b).e ? 1 : -1;
}

int main()
{
	int n, tot = 0,oper = 0, check = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> mt[i].s >> mt[i].e;
//	for (int i = 0; i < n; i++)
//		mt[i].exist = true;

	qsort(mt, n, sizeof(mt[0]), cmp);
	
	 while(check < n)
	 {
	 	if (mt[oper].e <= mt[check].s)
	 	{
	 		oper = check;
		}
		else
		{
			tot++;
		}
		check++;
	 }
	 
	 cout << tot;
}
