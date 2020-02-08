//#include<iostream>
#include<cstring>
#include<algorithm>
#include<fstream>
#include<climits>
 
using namespace std;

struct BIG_NUM{
	static const int maxLength = 1000;   
	int integer[maxLength]; // bn.integer[0]表示最低位，即个位 
	int length;
	bool positive;
	BIG_NUM(const long long n = 0){memset(integer,0,sizeof(integer));length = 0; positive = true;*this = n;}
	BIG_NUM(const char* a){memset(integer,0,sizeof(integer));length = 0; positive = true;*this = a;}
	
//BIG_NUM的赋值
	BIG_NUM operator = (const BIG_NUM bn)
	{
		length = bn.length;
		for (int i = 0; i < length; i++)
			integer[i] = bn.integer[i];
		positive = bn.positive;
		return *this;
	}
	BIG_NUM operator = (const char* s)
	{
		length = strlen(s);
		int np = 0, sp = length - 1;
		if (s[0] == '-') positive = false, length--;
		while (np < length)
			integer[np] = s[sp] - '0', np++, sp--;
		return *this;
	}
	BIG_NUM operator = (const long long l)
	{
		int i = 0;
		long long n = l;
		if (l < 0) positive = false, n = -n;
		while (n != 0)
			integer[i++] = n % 10, n /= 10; 
		length = i;
		return *this;
	} 

//BIG_INT的大小比较
	int compare (const BIG_NUM& bn1, const BIG_NUM& bn2)
	{
		if (!bn1.positive && bn2.positive) return -1;
		if (bn1.positive && !bn2.positive) return 1;
		
		if (bn1.length < bn2.length) return -1;
		if (bn1.length > bn2.length) return 1;
		
		int p = length - 1;
		while (bn1.integer[p] == bn2.integer[p] && p > 0) p--;		
		if (bn1.integer[p] < bn2.integer[p]) return -1;
		if (bn1.integer[p] > bn2.integer[p]) return 1;
		return 0;
	}
	bool operator < (const BIG_NUM& bn2){return compare(*this,bn2) == -1;}
	bool operator > (const BIG_NUM& bn2){return compare(*this,bn2) == 1;}
	bool operator == (const BIG_NUM& bn2){return compare(*this,bn2) == 0;}
	bool operator <= (const BIG_NUM& bn2){return compare(*this,bn2) != 1;}
	bool operator >= (const BIG_NUM& bn2){return compare(*this,bn2) != -1;}
	bool operator != (const BIG_NUM& bn2){return compare(*this,bn2) != 0;}
	
//BIG_NUM的四则运算
	BIG_NUM operator - ()//取负 
	{
		BIG_NUM negative;
		negative = *this;
		negative.positive = !positive;
		return negative;
	}
	BIG_NUM operator + (const BIG_NUM& bn2)
	{
//		if (this->positive == false) return (*this - bn2);
//		if (this-)
		BIG_NUM sum;
		int p = 0, carry = 0, tempSum;
		while (p < length || p < bn2.length || carry != 0)
		{
			tempSum = carry;
			if (p < length) tempSum += integer[p];
			if (p < bn2.length) tempSum += bn2.integer[p];
			carry = tempSum / 10;
			sum.integer[p] = tempSum % 10;
			sum.length = ++p;
		}
		return sum;
	}	
	BIG_NUM operator * (const BIG_NUM& bn2)
	{
		BIG_NUM ans;
		ans.length = length + bn2.length - 1; // 假定不会进位 
		for (int i = 0; i < length; i++)
			for (int j = 0; j < bn2.length; j++)
				ans.integer[i+j] += integer[i] * bn2.integer[j];
		int carry = 0;
		for (int i = 0; i < ans.length + 1; i++)
		{
			ans.integer[i] += carry;
			carry = ans.integer[i] / 10;
			ans.integer[i] %= 10;
		}
		if (ans.integer[ans.length]) ans.length++; //如果会进位，那么ans.integer[ans.length]必然不等于0 
		return ans;
	}
//	BIG_NUM operator - (const BIG_NUM& bn2)
//	{
//		 BIG_NUM bn4 = *this + (-bn2);
//		return bn4;
//	}
}; 

//BIG_NUM的输入、输出 
istream& operator >> (istream& in, BIG_NUM& bn)
{
	char s[bn.maxLength];
	in >> s;
	bn = s;
	return in;
}
ostream& operator << (ostream& out, const BIG_NUM& bn)
{
	if (bn.positive == false) out << "-";
	for (int i = bn.length - 1; i >= 0; i--)
		out << bn.integer[i];
	return out;
}

//int main()
//{
//	//ifstream in;
//	//in.open("BIG_INT.txt");
//	
//	BIG_NUM bn1 = "5", bn2 = 2;
//	cin >> bn1;
//	cout << bn1; 
//}

