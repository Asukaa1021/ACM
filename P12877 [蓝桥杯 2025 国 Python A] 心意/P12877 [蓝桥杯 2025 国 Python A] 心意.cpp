#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],b[500005],sa[500005],sb[500005];
int lg1[500005];int n;
int h1[500005];
int h2[500005];
int lg2[500005];
const int base = 13331;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) 
	{
		cin >> a[i];
		sa[i] = a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> b[i];
		sb[i] = b[i];
	}
	sort(sa + 1,sa + 1 + n);
	sort(sb + 1,sb + 1 + n);
	
	int d = sb[1] - sa[1];
	for(int i = 1;i <= n;i++)
	{
		b[i] -= d;
	}
	int tmp1 = 0,tmp2 = 0;
	lg1[0] = lg2[0] = 1;
	for(int i = 1;i <= n;i++)
	{
		lg1[i] = lg1[i - 1] * base % mod1;
		lg2[i] = lg2[i - 1] * base % mod2;
	}
	for(int i = 1;i <= n;i++)
	{
		h1[i] = (h1[i - 1] * base + a[i]) % mod1;
		h2[i] = (h2[i - 1] * base + a[i]) % mod2;
	}
	for(int i = 1;i <= n;i++)
	{
		tmp1 = (tmp1 + b[i] * lg1[n - i] % mod1) % mod1;
		tmp2 = (tmp2 + b[i] * lg2[n - i] % mod2) % mod2;
	}
	for(int k = 0;k < n;k++)
	{
		int rot1 = (h1[n] - h1[k] * lg1[n - k] % mod1 + mod1) % mod1;
		int sum1 = (rot1 * lg1[k] % mod1 + h1[k]) % mod1;
		
		int rot2 = (h2[n] - h2[k] * lg2[n - k] % mod2 + mod2) % mod2;
		int sum2 = (rot2 * lg2[k] % mod2 + h2[k]) % mod2;
		
		if(tmp1 == sum1 && tmp2 == sum2)
		{
			cout << k << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}