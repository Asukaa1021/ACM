#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++) cin >> a[i];
	
	stack<pair<int,int>> stk;
	int cursum = 0;
	int ans = 0;
	for(int i = n - 1;i >= 0;i--)
	{
		int cnt = 1;//每个元素开始贡献为1
		while(stk.size() && a[stk.top().first] == a[i] + 1)
		{
			cnt += stk.top().second;
			cursum -= stk.top().second;
			stk.pop();
		}
		
		stk.push({i,n - i});//栈顶元素贡献为后缀长度
		cursum += n - i;
		ans += cursum;
	//	cout << cursum << ' ';
	}
	cout << ans << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) solve();
}
