#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 300005;
int n,m,ans = 0;
int a[N];
int xorSum[N];

bool check(int tag,int m)
{
	int cur_xor = 0;
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		cur_xor ^= a[i];
		if(((cur_xor & tag) == tag) && cnt < m - 1)
		{
			cnt++;
			cur_xor = 0;
		}
	}
	if(cnt == m - 1 && ((cur_xor & tag) == tag)) return true;
	else return false;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) 
	{
		cin >> a[i];
		xorSum[i] = xorSum[i - 1] ^ a[i];//异或前缀和
	}
	for(int k = 30;k >= 0;k--)
	{
		int target = ans | (1 << k);
		if(check(target,m))
		{
			ans = target;
		}
	}
	cout << ans << endl;
}
