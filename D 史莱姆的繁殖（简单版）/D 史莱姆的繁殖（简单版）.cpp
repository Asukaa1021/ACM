#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++) cin >> a[i];
	stack<int> stk;
	for(int i = n - 1;i >= 0;i--)
	{
		if(stk.size())
		{
			while(stk.size() && stk.top() == a[i] + 1)
			{
				stk.pop();
			}
		}
		stk.push(a[i]);
	}
	
	cout << stk.size() << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) solve();
}