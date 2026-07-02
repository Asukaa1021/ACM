#include<bits/stdc++.h>
#define int long long 
using namespace std;
vector<vector<bool>> can_be_attack;
int ans = 0;
int n,m,k;
void trav(int x,int y,int p);
struct Attack
{
	int t,x,y;
};

bool cmp(Attack a,Attack b)
{
	return a.t < b.t;
}

void solve()
{
	ans = 0;
	cin >> n >> m >> k;
	vector<string> Mp(n + 1);
	for(int i = 1;i <= n;i++)
	{
		cin >> Mp[i];
		Mp[i] = " " + Mp[i];
	}
	vector<Attack> attack;
	for(int i = 0;i < k;i++)
	{
		int x,y,t;
		cin >> x >> y >> t;
		attack.push_back({t,x,y});
	}
	sort(attack.begin(),attack.end(),cmp);	
	
	for(int p = 1;p <= 4;p++)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)//枚举方向坐标
			{
				if(Mp[i][j] == 'x')
				{
					can_be_attack.clear();
					can_be_attack.resize(n + 1,vector<bool> (m + 1));
					trav(i,j,p);
					vector<vector<int>> tot(n + 1,vector<int> (m + 1));
		
					int cx = -1,cy = -1;
					for(int u = 0;u < k;u++)
					{
						auto [t,x,y] = attack[u];
						tot[x][y]++;
					
						if(1 <= x && x <= n && 1 <= y && y <= m && can_be_attack[x][y]) cx = x,cy = y;
						int sum = 0;
						
						if(cx != -1 && cy != -1)
						{
							for(int dx = -1;dx <= 1;dx++)
							{
								for(int dy = -1;dy <= 1;dy++)
								{
									int xx = cx + dx;
									int yy = cy + dy;
									
									if(1 <= xx && xx <= n && 1 <= yy && yy <= m) sum += tot[xx][yy];
								}
							}
							ans = max(ans,sum);
						}
					}
				}
			}
		}
		
	}
	cout << ans << '\n';
}

void trav(int x,int y,int p)
{
	for(int dx = -4;dx <= 4;dx++)
	{
		for(int dy = -4;dy <= 4;dy++)
		{
			int sum = abs(dx) + abs(dy);
			if(sum > 4) continue;
			if(p == 1 && (dx < 0 || abs(dy) > 2)) continue; 
			if(p == 2 && (dy < 0 || abs(dx) > 2)) continue; 
			if(p == 3 && (dx > 0 || abs(dy) > 2)) continue; 
			if(p == 4 && (dy > 0 || abs(dx) > 2)) continue; 
			int xx = x + dx;
			int yy = y + dy;
			if(1 <= xx && xx <= n && 1 <= yy && yy <= m)
				can_be_attack[xx][yy] = true;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) solve();
}
