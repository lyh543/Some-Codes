#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MaxN = 100010;
int n, a[MaxN];
LL A, B;
LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}
int main()
{
	freopen("tourist.in", "r", stdin);
	freopen("tourist.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), A += a[i];
	sort(a + 1, a + n + 1);
	B = n;
	for (int i = 1; i < n; ++i) 
		A += 2ll * i * (n - i) * (a[i + 1] - a[i]);
    LL g = gcd(A, B);
	printf("%I64d %I64d\n", A / g, B / g);
	fclose(stdin);
	fclose(stdout);
}