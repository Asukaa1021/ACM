#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int a,b,n,m;
	cin >> a >> b >> n >> m;
	if(m == 1)
	{
		cout << "NO" << endl;
		return;
	}
	else
	{
		bool flg = false;
		int lam = n / m;
		if(n % m == 1) flg = true;
		int aa = lam * lam;
		int bb = lam * (lam + (flg));
		if((aa <= a && bb <= b) || (aa <= b && bb <= a)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

signed main()
{
	int T;
	cin >> T;
	while(T--) solve();
}
