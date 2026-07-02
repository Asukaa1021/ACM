#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	cin >> n;
	int c = 0;
	vector<int> a(n);
	map<int,int> mp;
	for(int i = 0;i < n;i++) 
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	int sum = 0;
	vector<int> e;
	
	for(auto i = mp.begin();i != mp.end();i++)
	{
		if((*i).second >= 2) 
		{
			sum += ((*i).second / 2 * 2) * (*i).first;
			c += (*i).second / 2 * 2;
			(*i).second %= 2;
		}
		if((*i).second > 0) e.push_back((*i).first);
	}
	int plus1 = 0,plus2 = 0,plus = 0;
	for(int i = e.size() - 1;i >= 0;i--)
	{
		if(e[i] < sum)
		{
			plus1 = e[i];
			break;
		}
	}
	for(int i = e.size() - 1;i >= 1;i--)
	{
		if(e[i] < e[i - 1] + sum)
		{
			plus2 = e[i] + e[i - 1];
			break;
		}
	}
	plus = max(plus1,plus2);
	if(c == 0) 
		cout << 0 << '\n';
	else if(c == 2 && plus == 0) 
		cout << 0 << '\n';
	else 
		cout << plus + sum << '\n';
	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) solve();
}