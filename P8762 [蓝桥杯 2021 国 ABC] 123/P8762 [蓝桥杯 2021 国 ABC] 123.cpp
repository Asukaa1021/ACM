#include<bits/stdc++.h>
using namespace std;

bool check(unsigned long long k,unsigned long long x)
{
	if(k * (k + 1) / 2 <= x) return true;
	else return false;
}

unsigned long long cnt(unsigned long long x)
{
	unsigned long long k = 0,sum = 0;
	unsigned long long l,r;
	l = 1,r = 1e12;
	while(l <= r)
	{
		unsigned long long mid = (r - l) / 2 + l;
		if(check(mid,x))
		{
			k = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	
	unsigned long long les = x - k * (k + 1) / 2;
	return k * (k + 1) * (k + 2) / 6 + les * (les + 1) / 2;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		unsigned long long l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",cnt(r) - cnt(l - 1));
	}
}