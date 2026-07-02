#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	string s;
	cin >> n >> s;
	s = " " + s;
	vector<int> idx(n + 5,n + 1);
	vector<int> cnt(n + 5);
	for(int i = n;i >= 1;i--)
	{
		if(s[i] == '(') idx[i] = i;
		else idx[i] = idx[i + 1];
		if(s[i] == '(') cnt[i]++;
		cnt[i] += cnt[i + 1];
	}
//	for(int i = 1;i <= n;i++) cout << cnt[i] << " " << idx[i] << endl;
	int ans = -1;
	
	for(int i = 1;i <= n;i++)
	{
		if(s[i] == ')')
		{
			int j = idx[i];
			int d = j - i;
			if(cnt[j + 1] >= d)
			{
				ans = max(ans,n - 2 * d);
			}
		}
	}
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) solve();
}