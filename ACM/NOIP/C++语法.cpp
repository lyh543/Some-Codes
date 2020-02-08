#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<vector>
#include<queue>
#include<limits>
#include<ctime>
#include<cstdlib>

using namespace std;

struct line{
	int d;
};

typedef int array[10][20];//array a;即为定义int a[10][20]

int main(int argc, char *argv[]) //若调用test.exe a b c，则argc==4,argv={"test.exe","a","b","c"}  
{
	
//cout更改输出小数格式(1) (需要iomanip) 
cout << setiosflags(ios::fixed) << setprecision(3);

//cout更改输出小数格式(2)
cout.setf(ios_base::fixed, ios_base::floatfield);
cout.precision(4);

//数组初始化(需要cstring)
int a[100];
memset(a,0,sizeof(a));

//从文件输入、输出（1）（重定向版，需要cstdio）
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

//从文件输入、输出（2）（C++语言版，需要fstream）
int i;
ofstream output;
ifstream input;
output.open("output.txt");
input.open("input.txt");
input >> i;
output << i;

// 从文件输入、输出（3）（C语言版，需要cstdio） 
char* s;
FILE *fp1,*fp2;
fp1=fopen("input.txt","r");
fp2=fopen("output.txt","w");
fscanf(fp1,"%s",s);
fprintf(fp2,"Hello World! And \"input.txt\" is:%s",s);
fclose(fp1);
fclose(fp2); 

//计时 需要ctime
int time = clock() / CLOCKS_PER_SEC;

// 加速cin输入
ios::sync_with_stdio(false);
cin.tie(0);

//vector的使用方法（需要vector）
vector<int> v; //定义
v.push_back(1); //将1推进v数组
for (vector<int>::iterator iter = v.begin(); iter < v.end(); iter++)
//将v中每个元素进行for循环

//queue的使用方法（需要queue）
queue<int> q; //定义
priority_queue<int> q2;//proirity_queue里的数总是降序排列
q.push(1); //将1推进q队列
i = q.front(); q.pop();//将q的第一个数拿出并赋值为n
q2.push(1);
i = q2.top(); q2.pop();

//int最大值（需要limits）
cout << numeric_limits<int>().max();
cout << INT_MAX;

//将字符串转为数字 (需要cstdlib)
int ia=atoi("132");
long la=atol("489432781657");
double d=atof("1.123");

//动态分配内存(需要cstdlib)
int * p1 = (int*)(malloc(500*sizeof(int)));
free(p1);  
}

//运算符重载
bool operator < (line& a, line& b)
{
	return a.d>b.d;
}

//gcd，最大公因数
int gcd(int a, int b)
{
	return a == 0 ? b : gcd(b , a%b);
}
