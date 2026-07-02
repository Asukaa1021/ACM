#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod = 998244353;
int n,m,k,_size,cnt,ans;
map<int,int> mp;
vector<pair<int,int>> v1,v2;
signed main()
{
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
	{
		int num;
		cin >> num;
		mp[num]++;
		ans = (ans + num) % Mod;
	}
	_size = n;
	while(m--)
	{
		int x,y;
		cin >> x >> y;
		cnt += x;
		v1.clear();
		v2.clear();
		if(x < 0)
		{
			for(auto i : mp)
			{
				if(i.first + cnt > 0) break;
				ans = (ans - (i.first + cnt - x) * i.second % Mod + Mod) % Mod;
				_size = (_size - i.second + Mod) % Mod;
				v1.push_back(i);
			}
			ans = (ans + _size * x % Mod + Mod) % Mod;
		}
		else
		{
			ans = (ans + _size * x % Mod) % Mod;
			for(auto it = mp.rbegin();it != mp.rend();it++)
			{
				auto i = *it;
				if(i.first + cnt <= k) break;
				_size = (_size + (i.first + cnt - k) * i.second % Mod) % Mod;
				v1.push_back(i);
				v2.push_back({1 - cnt,i.second * (i.first + cnt - k)});
				v2.push_back({k - cnt,i.second});
			}
		}
		if(y)
		{
			_size = (_size + 1) % Mod;
			ans = (ans + y) % Mod;
			v2.push_back({y - cnt,1});
		}
		for(auto i : v1)
		{
			mp.erase(i.first);
		}
		for(auto i : v2)
		{
			mp[i.first] = (mp[i.first] + i.second) % Mod;
		}
		cout << ans << endl;
	}
}
