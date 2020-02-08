//紫书P434 
#include<iostream>
#include<cmath>

using namespace std;

int ansPlus1(int); //将第int题的答案加一 
char processAns1();
char processAns2();
char processAns3();
char processAns4();
char processAns5();
char processAns6();
char processAns7();
char processAns8();
char processAns9();
char processAns10();


char supposeAns[11];

int main()
{
	for (int i = 1; i < 11; i++)
		supposeAns[i] = 'A'; //将所有题的答案设为A
	do
	{
		if (processAns1() == supposeAns[1] &&
			processAns2() == supposeAns[2] &&
			processAns3() == supposeAns[3] &&
			processAns4() == supposeAns[4] &&
			processAns5() == supposeAns[5] &&
			processAns6() == supposeAns[6] &&
			processAns7() == supposeAns[7] &&
			processAns8() == supposeAns[8] &&
			processAns9() == supposeAns[9] &&
			processAns10() == supposeAns[10])
		{
			for (int i = 1; i < 11; i++)
			{
				cout << i << supposeAns[i] << " ";
			}
			cout << endl;
		}
	}
	while (ansPlus1(10)); 
}

int ansPlus1(int n)
{
	if (n == 1 && supposeAns[1] == 'E')
		return 0; //完成所有循环
	if (supposeAns[n] == 'E')
	{
		supposeAns[n] = 'A';
		return ansPlus1(n - 1);//如果第n题答案已经是E，则将n题答案设为A，并把n-1题答案加1 
	}
	else
	{
		supposeAns[n]++;
		return 1;
	}
}

char processAns1()
{
	for (int i = 2; i <= 6; i++)
	{
		if (supposeAns[i] == 'B') //第一个选B的题 
		{
			return(i + 63); // 2 + 63 = 65 ('A')
		}
	}
	return 0;
}

char processAns2()
{
	int ans = 0;
	for (int i = 1; i <= 9; i++)
	{
		if (supposeAns[i] == supposeAns[i + 1]) //两个连续问题答案相同 
		{
			if (ans == 0)
			{
				ans = i;	
			}
			else
			{
				return 0; // 有多个选项满足答案 
			}
		}
	}
	return(ans + 63);
}

char processAns3()
{
	int choice[] = { 1, 2, 4, 7, 6 };
	int ans = -1;
	for (int i = 0; i < 5; i++)
	{
		if (supposeAns[3] == supposeAns[choice[i]])
		{
			if (ans != -1)
			{
				return 0;
			}
			ans = i;
		}
	}
	return(ans + 65);
}

char processAns4()
{
	int ans = 0;
	for (int i = 1; i < 11; i++)
	{
		if (supposeAns[i] == 'A') //计算答案是A的问题的个数 
			ans++;
	}
	return(ans + 65);
}

char processAns5()
{ 
	int choice[] = { 10, 9, 8, 7, 6 };
	int ans = -1;
	for (int i = 0; i < 5; i++)
	{
		if (supposeAns[5] == supposeAns[choice[i]])
		{
			if (ans != -1)
			{
				return 0;
			}
			ans = i;
		}
	}
	return(ans + 65);
}

char processAns6()
{
	int n_a, n_b, n_c, n_d, n_e;
	for (int i = 1; i < 11; i++)
	{
		switch (supposeAns[i])
		{
		case 'A':n_a++;break;
		case 'B':n_b++;break;
		case 'C':n_c++;break;
		case 'D':n_d++;break;
		case 'E':n_e++;break;
		}
	}
	if (n_a == n_b) return 'A';
	if (n_a == n_c) return 'B';
	if (n_a == n_d) return 'C';
	if (n_a == n_e) return 'D';
	return 'E';
}

char processAns7()
{
	return(69 - abs(supposeAns[8] - supposeAns[7])); //
}

char processAns8()
{
	int ans = 0;
	for (int i = 1; i < 11; i++)
	{
		if (supposeAns[i] == 'A' || supposeAns[i] == 'E') //计算答案是A或E的问题的个数 
			ans++;
	}
	return(ans + 63);
}

char processAns9()
{
	int ans = 0;
	for (int i = 1; i < 11; i++)
	{
		if (supposeAns[i] == 'B' || supposeAns[i] == 'C' || supposeAns[i] == 'D') //计算答案是B,C或D的问题的个数 
			ans++;
	}
	switch (ans)
	{
	case 3:
	case 7:return 'A';
	case 6:return 'B';
	case 4:
	case 9:return 'C';
	case 8:return 'D';
	case 10: return 'E';
	default:
		break;
	}
}

char processAns10()
{
	return supposeAns[10];
}
