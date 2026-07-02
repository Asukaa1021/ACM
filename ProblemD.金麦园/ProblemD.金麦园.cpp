#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans;
long long num[1000005];
long long preSum[1000005];
long long Max = 0;

bool check(long long x)
{
	long long cnt = 0;
	long long j = 1;
	for(int i = 1;i <= n;i++)
	{
		while(j <= n && num[j] - num[i] <= x) j++;
		cnt += j - i - 1;
		if(cnt >= m) return true;
	}
	return false;
} 

pair<long long,long long> Count(long long x)
{
	long long cnt = 0;
	long long sum = 0;
	
	long long j = 1;
	for(int i = 1;i <= n;i++)
	{
		while(j <= n && num[j] - num[i] <= x) j++;
		cnt += j - i - 1;
		sum += (preSum[j - 1] - preSum[i]) - (j - i - 1) * num[i] ;
	}
	return {cnt,sum};
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> num[i];
		Max = max(Max,num[i]);
	 } 
	sort(num + 1,num + 1 + n);
	for(int i = 1;i <= n;i++)
	{
		preSum[i] += preSum[i - 1] + num[i];
	}
	long long l,r;
	l = 0,r = 1e8 + 5;
	while(l <= r)
	{
		long long mid = l + r >> 1;
		if(check(mid))
		{
			ans = mid;
			r = mid - 1;
		}	
		else l = mid + 1;
	}
	long long c = Count(ans - 1).first;
	long long sum2 = Count(ans - 1).second;
	cout << sum2 + (m - c) * ans << endl;
}