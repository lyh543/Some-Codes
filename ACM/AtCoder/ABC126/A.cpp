#include<iostream>

using namespace std;

int main()
{
  char a[100];
  int n, k;
  cin >> n >> k >>a;
  a[k-1] += 32;
  cout << a;
}

