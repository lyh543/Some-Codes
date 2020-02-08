//微软学生俱乐部 2019 年会 混乱代码大赛

//version 1.0 with "define everything to int" and "goto and switch" and expected output
#include <iostream>
#define iNT std::cout << 
#define Int 5
#define INt goto
//used: int inT iNt iNT Int InT INt INT lnt

char INT[Int*Int] = "lNt";
char* iNt = INT;

int lnt()
{
	InT:
	if (INT != iNt)
		INt inT;
	(*iNt) -= (1 << Int) - 1;
	iNt++;
	inT:
	if (INT == iNt)
		INt InT;
	INT[Int]++;
	(*iNt)++;
	if (*(INT + Int) < Int)
		INt inT;
	return Int;
}

int main()
{
	lnt();
	(*(++iNt))--;
	*iNt -= '1';
	lnt();
	iNT(INT);
}



/* version 0.2 with "goto and switch" and expected output
#include <iostream>
using namespace std;

char INT[4*4] = "lNT";
char* p = INT;

int foo()
{
goto2:
	if (INT != p)
		goto goto1;
	(*p) -= (1 << 5) - 1;
	p++;
goto1:
	if (INT == p)
		goto goto2;
	INT[5]++;
	(*p)++;
	if (*(INT + 5) < 5)
		goto goto1;
	return 5;
}

int main()
{
	foo();

	(*(++p))--;
	*p -= 17;
	foo();
	cout << INT;
}
*/

/*version 0.1 with expected output

#include <iostream>
using namespace std;

char INT[6] = "lNT";

int main()
{
	char* p = INT;
	(*p) -= (1<<5) - 1;
	p++;

	goto1:
	INT[5]++;
	(*p)++;
	if (*(INT+5) < 5)
		goto goto1;

	*(++p) = 'C';
	cout << INT;
}

*/
