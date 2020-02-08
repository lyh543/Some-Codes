#include<iostream>

using namespace std;

int main()
{
	int n[7];
	for (int i = 1; i <= 6; i++)
		cin >> n[i];
	
	//¿¼ÂÇ6x6	
	int tot = n[6];
	n[6] = 0;
	
	//¿¼ÂÇ5x5
	tot += n[5];
	if (n[1] * 11 > n[5])
	{
		n[1] -= n[5] * 11; //Ò»¸ö5x5´îÅä11¸ö1x1 
	}
	else
	{
		n[1] = 0;
	}
	n[5] = 0;
	
	//¿¼ÂÇ4x4
	tot += n[4];
	if (n[2] * 5 > n[4])
	{
		n[2] -= n[4] * 5;
	}
	else
	{
		if (n[1] > n[4]*20 - n[2]*4)
		{
			n[1] -= n[4]*20 - n[2]*4;
		}
		else
		{
			n[1] = 0;
		}
		n[2] = 0;
	}
	n[4] = 0;
	
	//¿¼ÂÇ3x3
	tot += n[3] / 4;
	n[3] = n[3] % 4;
	if (n[3] != 0)
	{
		tot++;
		if (n[3] == 1)
		{
			n[2] -= 5;
			n[1] -= 7;
		}
		if (n[3] == 2)
		{
			n[2] -= 3;
			n[1] -= 6; 
		} 
		if (n[3] == 3)
		{
			n[2] -= 1;
			n[1] -= 5;
		}
	}
	
	if (n[1] < 0) n[1] = 0;
	n[1] += n[2] * 4;    
	
	if (n[1] > 0)
	{
		tot += n[1] / 36;
		if (n[1] % 36 != 0)
			tot++;
	}
	
	cout << tot;
}
