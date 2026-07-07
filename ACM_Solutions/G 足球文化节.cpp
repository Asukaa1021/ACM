#include<bits/stdc++.h>
#define int long long
using namespace std;


signed main()
{
	int n,m;
	cin >> n >> m;
	map<pair<int,int>,int> mp;
	map<int,int> q;
	map<int,int> abcnt;
	int cnt = 0;
	int p = 0;
	bool f = false;
	for(int i = 1;i <= n;i++)
	{
		int a,b;
		cin >> a >> b;
		if(a > b) swap(a,b);
		mp[{a,b}]++;
		if(mp[{a,b}] == 2) 
		{
			p++;
			q[a]++;
			q[b]++;
			if(q[a] == 1) cnt++;
			if(q[b] == 1) cnt++;
		}
	}
	//cout << cnt << '\n';
	if(cnt != m)
	{
		for(int i = 1;i <= m;i++)
		{
			if(q[i] == 0)
			{
				cout << 1 << '\n' << i << '\n';
				return 0;
			}
		}
	}
	else if(p == m * (m - 1) / 2)
	{
		if(m == 2) 
		{
			cout << -1 << '\n';
		}
		else cout << 3 << '\n' << "1 2 3" << '\n';
		return 0;
	}
	else
	{
		for(int i = 1;i <= m;i++)
		{
			for(int j = 1;j < i;j++)
			{
				if(mp[{j,i}] <= 1)
				{
					cout << 2 << '\n' << i << " " << j << '\n';
					return 0;
				}
			}
		}
	}
}
