#include<bits/stdc++.h>
#define int long long 
using namespace std;
string num;
int ans = LLONG_MAX;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> num;
	int len = num.size();
	num = " " + num;
	deque<int> q;
	int cnt[15];
	memset(cnt,0,sizeof cnt);
	for(int i = 1;i <= len;i++)
	{
		q.push_back(num[i] - '0');
		cnt[num[i] - '0']++;
		while(q.size() > 10)
		{
			cnt[q.front()]--;
			q.pop_front();
		}
		if(q.size() == 10)
		{
			vector<int> a,b;
			for(int u = 0;u <= 9;u++)
			{
				int k = cnt[u];
				while(k > 1)
				{
					k--;
					a.push_back(u);
				}
				if(k == 0) b.push_back(u);
			}
			int sum = 0;
			for(int u = 0;u < a.size();u++)
			{
				sum += abs(a[u] - b[u]);
			}
			ans = min(ans,sum);
		}
	}
	cout << ans << endl;
}