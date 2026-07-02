#include<bits/stdc++.h>
using namespace std;
int n,m;
int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,1,-1,0,1,-1,0};

struct node
{
	int x,y;
};

vector<vector<int>> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		mp.resize(n + 1,vector<int> (m + 1));
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
				cin >> mp[i][j];
		vector<vector<node>> pos;
		pos.resize(n + m);
		for(int i = 1;i <= n;i++)
			pos[mp[i][1]].push_back({i,1});
		for(int i = 1;i <= m;i++)
			pos[mp[n][i]].push_back({n,i});
		
		for(int k = 0;;k++)
		{
			if(pos[k].empty())
			{
				cout << k << '\n';
				break;
			}
			else
			{
				bool flg = true;
				for(auto [curX,curY] : pos[k])
				{
					queue<node> q;
					vector<vector<bool>> vis(n + 1,vector<bool> (m + 1));
					vis[curX][curY] = true;
					q.push({curX,curY});
					while(!q.empty())
					{
						auto [x,y] = q.front();
						q.pop();
						if(x == 1 || y == m)
						{
							flg = false;
							break;
						}
						for(int i = 0;i < 8;i++)
						{
							int newX = x + dx[i];
							int newY = y + dy[i];
							if(1 <= newX && newX <= n 
							&& 1 <= newY && newY <= m 
							&& !vis[newX][newY])
							{
								if(mp[newX][newY] != mp[curX][curY]) continue;
								vis[newX][newY] = true;
								q.push({newX,newY});
							}
						}
					}
				}
				if(flg)
				{
					cout << k << '\n';
					break;
				}
			}
		}
	}
}
