#include<bits/stdc++.h>
using namespace std;

int n;
long long x;
long long cnt;
long long ans;
vector<long long> u;
vector<long long> d;
vector<long long> u2;
vector<long long> d2;

void f(long long k)
{
	if(abs(u2[k] - u2[k + 1]) > x)
	{
		if(u2[k] > u2[k + 1])
		{
			cnt += u2[k] - u2[k + 1] - x;
			u2[k] = u2[k + 1] + x;
			if(k >= 2)
			{
				f(k - 1);
			}
		}
		else
		{
			cnt += u2[k + 1] - u2[k] - x;
			u2[k + 1] = u2[k] + x;
		}
	}
}

bool check(long long mid)
{

	for(int i = 1;i <= n;i++)
	{
		u2[i] = u[i];
		d2[i] = d[i];
	}
	for(int i = 1;i < n;i++)
	{
		f(i);
	}
	long long h = LONG_MAX;
	for(int i = 1;i <= n;i++)
	{
		h = min(h,u2[i] + d2[i]);
	}
	for(int i = 1;i <= n;i++)
	{
		cnt += u2[i] + d2[i] - h;
	}
	if(cnt <= mid) return true;
	return false;
}

int main()
{
	cin >> n >> x;
	u.resize(n + 1);
	d.resize(n + 1);
	u2.resize(n + 1);
	d2.resize(n + 1);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld%lld",&u[i],&d[i]);
	}
	long long l = 0,r = 1e15;
	while(l <= r)
	{
		long long mid = (r - l) / 2 + l;
		cnt = 0;
		if(check(mid))
		{
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << endl;
}