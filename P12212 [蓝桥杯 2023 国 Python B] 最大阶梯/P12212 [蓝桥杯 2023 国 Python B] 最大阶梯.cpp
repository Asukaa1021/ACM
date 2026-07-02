#include<bits/stdc++.h>

using namespace std;

int dx[4] = {1,1,-1,-1};
int dy[4] = {1,-1,1,-1};

int mp[1005][1005];
int n;
int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			scanf("%d",&mp[i][j]);
		}
	}
	int Maxlen = 1;
	for(int u = 0;u < 4;u++)
	{
		int xx = dx[u];
		int yy = dy[u];
		vector< vector<int> > flg(n + 1,vector (n + 1,1));
		if(xx == 1 && yy == 1)
		{
			for(int i = n;i >= 1;i--)
			{
				for(int j = n;j >= 1;j--)
				{
					int x = i + xx;
					int y = j + yy;
					if(1 <= x && x <= n && 1 <= y && y <= n)
						if(mp[x][j] == mp[i][j] && mp[i][y] == mp[i][j])
						{
							flg[i][j] = min(flg[x][j],flg[i][y]) + 1;
							Maxlen = max(Maxlen,flg[i][j]);
						}
						else flg[i][j] = 1;
					else flg[i][j] = 1;
				}
			}
		}
		if(xx == -1 && yy == -1)
		{
			for(int i = 1;i <= n;i++)
			{
				for(int j = 1;j <= n;j++)
				{
					int x = i + xx;
					int y = j + yy;
					if(1 <= x && x <= n && 1 <= y && y <= n)
						if(mp[x][j] == mp[i][j] && mp[i][y] == mp[i][j])
						{
							flg[i][j] = min(flg[x][j],flg[i][y]) + 1;
							Maxlen = max(Maxlen,flg[i][j]);
						}
						else flg[i][j] = 1;
					else flg[i][j] = 1;
				}
			}
		}
		if(xx == 1 && yy == -1)
		{
			for(int i = n;i >= 1;i--)
			{
				for(int j = 1;j <= n;j++)
				{
					int x = i + xx;
					int y = j + yy;
					if(1 <= x && x <= n && 1 <= y && y <= n)
						if(mp[x][j] == mp[i][j] && mp[i][y] == mp[i][j])
						{
							flg[i][j] = min(flg[x][j],flg[i][y]) + 1;
							Maxlen = max(Maxlen,flg[i][j]);
						}
						else flg[i][j] = 1;
					else flg[i][j] = 1;
				}
			}
		}
		if(xx == -1 && yy == 1)
		{
			for(int i = 1;i <= n;i++)
			{
				for(int j = n;j >= 1;j--)
				{
					int x = i + xx;
					int y = j + yy;
					if(1 <= x && x <= n && 1 <= y && y <= n)
						if(mp[x][j] == mp[i][j] && mp[i][y] == mp[i][j])
						{
							flg[i][j] = min(flg[x][j],flg[i][y]) + 1;
							Maxlen = max(Maxlen,flg[i][j]);
						}
						else flg[i][j] = 1;
					else flg[i][j] = 1;
				}
			}
		}
		if(Maxlen == n) break;
	}
	cout << Maxlen << endl;
}