#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,num = 0;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++) cin >> a[i];
	vector<int> temp = a;
	sort(temp.begin(),temp.end());
	temp.erase(unique(temp.begin(),temp.end()),temp.end());
	for(int i = 0;i < a.size();i++)
	{
		int pos = lower_bound(temp.begin(),temp.end(),a[i]) - temp.begin();
		a[i] = pos;
	}
	
	vector<int> cnt(n);
	for(int i = 0;i < n;i++)
	{
		int j = i;
		while(j < n - 1 && a[j + 1] == a[j]) j++;
		cnt[a[i]]++;
		i = j;
	}
	vector<int> used;
	bool flg = true;
	for(int i = 0;i < n;i++)
	{
		if(cnt[i] > 1)
		{
			flg = false;
			if(cnt[i] > 3)
			{
				cout << "NO" << '\n';
				return;
			}
			else
			{
				for(int j = 0;j < n;j++)
				{
					if(a[j] == i && (j == 0 || a[j - 1] != i)) used.push_back(j);
					else if(a[j] == i && (j == n - 1 || a[j + 1] != i)) used.push_back(j);
					if(a[j] == i)
					{
						if(j != 0 && a[j - 1] != i) used.push_back(j - 1);
						if(j != n - 1 && a[j + 1] != i) used.push_back(j + 1);
					}
				}
				break;
			}
		}
	}
	if(flg)
	{
		cout << "YES" << '\n';
		return;
	}
	for(int i = 0;i < used.size();i++)
	{
		for(int j = 0;j < used.size();j++)
		{
			if(i == j) continue;
			bool suc = true;
			swap(a[used[i]],a[used[j]]);
			vector<int> cnt2(n);
			for(int p = 0;p < n;p++)
			{
				int q = p;
				while(q < n - 1 && a[q] == a[q + 1]) q++;
				cnt2[a[p]]++;
				if(cnt2[a[p]] > 1) 
				{
					suc = false;
					break;
				}
				p = q;
			}
			if(suc)
			{
				cout << "YES" << '\n';
				return;
			}
			swap(a[used[i]],a[used[j]]);
		}
	}
	cout << "NO" << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) solve();
}
