#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[300005],b[300005];
long long ans;

bool check(long long x)
{
	long long k = m * n;
	long long cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		if(a[i] <= b[i])
		{
			cnt += (x + b[i] - 1) / b[i];
			if(cnt > k) return false;
		}
		else//a[i] > b[i]
		{
			if(m * a[i] >= x)
			{
				cnt += (x + a[i] - 1) / a[i];
			} 
			else
			{
				cnt += m + (x - a[i] * m + b[i] - 1) / b[i];
				if(cnt > k) return false;
			}
		}
	}
	if(cnt <= k) return true;
	else return false;	
}


int main()
{
	cin >> n >> m;
	long long M = 0;
	for(int i = 1;i <= n;i++)
	{ 
		scanf("%d",&a[i]);
		M = max(M,a[i]);
	}
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&b[i]);
		M = max(M,b[i]);
	} 
	
	long long l = 1,r = M * m;
	
	while(l <= r)
	{
		long long mid = l + (r - l) / 2;
		
		if(check(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}
	cout << ans << endl;
}