#include<bits/stdc++.h>
using namespace std;

void solve()
{
	long long n,k;
	cin >> n >> k;
	k %= n;
	if(k == 0) 
	{
		cout << 0 << endl;
		return;
	}
	if((n - k) % 2 == 0) cout << (n - k) / 2 << endl;
	else if((n * 2 - k) % 2 == 0) cout << (n * 2 - k) / 2 << endl;
	else cout << -1 << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--) solve();
}
