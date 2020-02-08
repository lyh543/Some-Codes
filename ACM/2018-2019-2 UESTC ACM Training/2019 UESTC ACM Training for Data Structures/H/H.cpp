#include<bits/stdc++.h>
#define LL long long
using namespace std;

const long long maxn = 100005;

long long n, ans = LLONG_MIN, maxlength;
long long value[maxn], presum[maxn] = { 0 };//presum[i]=sum(1,...,i)
long long head = 1, endp = 1;

deque<long long> q; // to get min of presum, the deque is ascend

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> maxlength;
	for (long long i = 1; i <= n; i++)
	{
		cin >> value[i];
		presum[i] = presum[i - 1] + value[i];
	}

	for (endp = 1; endp <= n; endp++)
	//when finding max(presum[n] - presum[i])
	//i are m numbers before n (exclusive)
	// i is n-m ~ n-1 
	{
		//pop the id of numbers that is bigger than the current number
		//because the current number will remain till the bigger numbers are popped
		// in other words, whenever the current number is pushed, the bigger numbers have no affect on the mininum
		while (!q.empty() && presum[q.back()] >= presum[endp - 1])
		{
			q.pop_back();
		}

		//push the id (n-1)
		q.push_back(endp - 1);

		//when the real queue (not the deque) is longer than m
		//we should pop the first number 
		if (endp - head > maxlength)
		{
			//check if the number going to be popped is in the deque
			if (q.front() == 0)
			{
				q.pop_front();
			}
			if (q.front() == head)
				q.pop_front();
			head++;
		}

		ans = max(ans, presum[endp] - presum[q.front()]);
	}
	cout << ans;
}
