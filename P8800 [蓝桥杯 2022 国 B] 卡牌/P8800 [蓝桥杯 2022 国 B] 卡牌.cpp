#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
long long n,m;
vector<long long> a(N);
vector<long long> b(N);
bool check(long long x)
{
	long long cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		if(a[i] >= x) continue;
		if(x - a[i] > b[i]) return false;
		cnt += x - a[i];
	}
	if(cnt > m) return false;
	else return true;
}

int main()
{
	cin >> n >> m;
	long long M = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		M = max(M,a[i]);
	} 
	for(int i = 1;i <= n;i++) cin >> b[i];
	long long l = 0,r = M + m;
	long long ans = 0;
	while(l <= r)
	{
		long long mid = (r - l) / 2 + l;
		
		if(check(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans << endl;
}