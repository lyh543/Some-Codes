#include<bits/stdc++.h>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const ll maxn = 1e5 + 5, mod = 1e9 + 7;

int ans[] = { 5,21,12,2,1,4,6,1,4,4,1,0,1,1 };

int main()
{
	fastio;
	int a;
	cin >> a;
	cout << ans[a];
}

/*
First year

Vadik, Misha, Alex 
1. Ural SU Championship
2. subregional 
3. regional 
4. Ural Championship
5. Tatarstan Championship
---------------------------------------
second year
Vadik, Alex
1. Ural SU Championship

Vadik, Alex, Sasha
2. subregional 

Vadik, Alex, IvanB
3. regional

Vadik, Alex, Nikita
4. qualification for Ural Championship

Vadik, Nikita
5. Ural Championship
-----------------------------------
third year
Vadik, Alex, Fedor
1. subregional 
2. Ural SU Championship
3. regional 

Vadik, Fedor, IvanK
4. unique competition of ACM ICPC veterans and current teams

Fedor, Nikita 
5. qualification for the Ural Championship

(Vadik), Fedor, Nikita 
6. Ural Championship
-------------------------------------
fourth year
Vadik, Den, Egor
1. Ural SU Championship
2. Subregional 
3. All-Siberian Olympiad (in Novosibirsk)
4. regional

Vadik, Sasha, Xiaohong
5. Ural SU Championship(main contest, not Game Tournament, WTF)
---------------------------------------
after graduation
Vadik, Timothée, Alexandre
1. SWERC regional 
*/
