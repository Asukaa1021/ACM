#include<bits/stdc++.h>
#define int long long
using namespace std;


signed main()
{
	int n,m,qq;
	cin >> n >> m >> qq;
	vector<vector<int>> st(n + 1);
	vector<int> p;

	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= i;j++)
		{
			if(i % j == 0) st[j].push_back(i);
		}
	}

	for(int i = 1;i <= m;i++)
	{
		int op;
		cin >> op;
		vector<int> temp;
		if(op == 1)
		{
			int x,y;
			cin >> x >> y;
			
			vector<int> a = st[x];
			vector<int> b = st[y];
			int p1 = 0,p2 = 0;
			while(p1 < a.size() || p2 < b.size())
			{
				if(p1 >= a.size()) 
				{
					while(p2 < b.size())
					{
						temp.emplace_back(b[p2]);
						p2++;
					}
					break;
				}
				if(p2 >= b.size()) 
				{
					while(p1 < a.size())
					{
						temp.emplace_back(a[p1]);
						p1++;
					}
					break;
				}
				if(a[p1] == b[p2])
				{
					temp.emplace_back(a[p1]);
					p1++;
					p2++;
				}
				else if(a[p1] > b[p2])
				{
					temp.emplace_back(b[p2]);
					p2++;
				}
				else
				{
					temp.emplace_back(a[p1]);
					p1++;
				}
			}
			st.push_back(temp);
		}
		else if(op == 2)
		{
			int x,y;
			cin >> x >> y;
			vector<int> a = st[x];
			vector<int> b = st[y];
			int p1 = 0,p2 = 0;
			while(p1 < a.size() && p2 < b.size())
			{
				if(a[p1] == b[p2])
				{
					temp.emplace_back(a[p1]);
					p1++;
					p2++;
				}
				else if(a[p1] > b[p2]) p2++;
				else p1++;
			}
			st.push_back(temp);
		}
		else
		{
			int x;
			cin >> x;
			vector<int> a = st[x];
			int p = 0;
			for(int i = 1;i <= n;i++)
			{
				if(p < a.size() && a[p] == i) 
				{
					p++;
					continue;
				}
				temp.emplace_back(i);
			}
			st.push_back(temp);
		}
	}

	while(qq--)
	{
		int x,v;
		cin >> x >> v;
		vector<int> arr = st[x];
		int pos = lower_bound(arr.begin(),arr.end(),v) - arr.begin();
		if(pos >= arr.size() || arr[pos] != v)cout << "No" << '\n';
		else
		{
			cout << "Yes" << '\n';
		}
	}
}
