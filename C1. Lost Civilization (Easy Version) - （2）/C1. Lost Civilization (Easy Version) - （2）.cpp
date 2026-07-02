#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1;i <= n;i++) cin >> a[i];
	stack<int> stk;
	for(int i = n;i >= 1;i--)
	{
		while(!stk.empty() && a[i] == stk.top() - 1) stk.pop();
		stk.push(a[i]);
	}
	cout << stk.size() << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}
