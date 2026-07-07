#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<vector<int>> mp;
vector<vector<bool>> vis,ans;

bool ok = false;
		
void solve()
{
	cin >> n >> m;
	mp.clear();
	mp.resize(n + 1,vector<int> (m + 1));
	vis.clear();
	vis.resize(n + 1,vector<bool> (m + 1));
	
	ok = false;
	vis[1][1] = true;
	
	for(int i = 1;i <= n;i++)
	{
		string s;
		cin >> s;
		s = " " + s;
		for(int j = 1;j <= m;j++)
		{
			if(s[j] == '.') mp[i][j] += 1;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		string s;
		cin >> s;
		s = " " + s;
		for(int j = 1;j <= m;j++)
		{
			if(s[j] == '.') mp[i][j] += 2;
		}
	}

	if((m + n) % 2 == 1)
	{
		queue<pair<pair<int,int>,int>> q;
		q.push({{1,1},1});
		vis[1][1] = true;
		while(!q.empty() && !ok)
		{
			int x = q.front().first.first;
			int y = q.front().first.second;
			int t = q.front().second;
			q.pop();
			
			if(x == n && y == m) 
			{
				ok = true;
		//		cout << x << " " << y << '\n';
			}
			for(int u = 0;u < 4;u++)
			{
				int xx = x + dx[u];
				int yy = y + dy[u];
				if(1 <= xx && xx <= n && 1 <= yy && yy <= m && !vis[xx][yy])
				{
					if(mp[xx][yy] == 3 || mp[xx][yy] == 3 - t) 
					{
						vis[xx][yy] = true;
						q.push({{xx,yy},3 - t});
					}
				}
			}
		}
	}
	else
	{
		ans.clear();
		ans.resize(n + 1,vector<bool> (m + 1));
		queue<pair<pair<int,int>,int>> q;
		q.push({{1,1},1});
		vis[1][1] = true;
		
		while(!q.empty())
		{
			int x = q.front().first.first;
			int y = q.front().first.second;
			int t = q.front().second;
			q.pop();
			
			if(mp[x][y] == 3) 
			{
				ans[x][y] = 1;
		//		cout << x << " " << y << '\n';
			}
			for(int u = 0;u < 4;u++)
			{
				int xx = x + dx[u];
				int yy = y + dy[u];
				if(1 <= xx && xx <= n && 1 <= yy && yy <= m && !vis[xx][yy])
				{
					if(mp[xx][yy] == 3 || mp[xx][yy] == 3 - t) 
					{
						vis[xx][yy] = true;
						q.push({{xx,yy},3 - t});
					}
				}
			}
		}
		vis.clear();
		vis.resize(n + 1,vector<bool> (m + 1));
		q.push({{n,m},2});
		vis[n][m] = true;

		while(!q.empty() && !ok)
		{
			int x = q.front().first.first;
			int y = q.front().first.second;
			int t = q.front().second;
			q.pop();
			
			if(ans[x][y] == 1)
			{   
				ok = true;
			}
			
			for(int u = 0;u < 4;u++)
			{
				int xx = x + dx[u];
				int yy = y + dy[u];
				if(1 <= xx && xx <= n && 1 <= yy && yy <= m && !vis[xx][yy])
				{
					if(mp[xx][yy] == 3 || mp[xx][yy] == 3 - t) 
					{
						vis[xx][yy] = true;
						q.push({{xx,yy},3 - t});
					}
				}
			}
		}
		
	}
	
	if(ok) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}



signed main()
{
	int t;
	cin >> t;
	while(t--) solve();
}