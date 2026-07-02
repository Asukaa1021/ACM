#include<bits/stdc++.h>
#define int long long
const int modd = 998244353;
using namespace std;

int ex_gcd(int a,int b,int &x,int &y)
{
	if(b == 0)
	{
		x = 1,y = 0;
		return a;
	}
	int d = ex_gcd(b,a % b,y,x);
	y -= a / b * x;
	return d;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> jc(n + 1);
	jc[1] = 1;
	jc[0] = 1;
	for(int i = 2;i <= n;i++)
	{
		jc[i] = jc[i - 1] * i % modd;
	}
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		int j = n - i - (i - 1);
		if(i - 1 > n - i) continue;
		int x,y;
		ex_gcd(jc[j],modd,x,y);
		int res = (jc[n - i] * (x % modd) % modd + modd) % modd;
		res = res * jc[n - i] % modd;
		ans = (ans + res) % modd;
	}
	cout << ans << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t = 1;
	while(t--) solve();
}
