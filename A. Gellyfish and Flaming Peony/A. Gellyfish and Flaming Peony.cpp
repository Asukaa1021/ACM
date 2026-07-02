#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int g[N][N];

void solve()
{
	int n,k = 0;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++) 
	{
		cin >> a[i];
		k = g[k][a[i]];
	}
	bool same = false;
	for(int i = 0;i < n;i++)
	{
		if(a[i] == k)
		{
			same = true;
			break;
		}
	}
	if(same)
	{
		int cnt = 0;
		for(int i = 0;i < n;i++) if(a[i] != k) cnt++;
		cout << cnt << '\n';
	}
	else
	{
		for(int i = 0;i < n;i++) a[i] /= k;
		int f[5005];
		memset(f,0x3f,sizeof f);
		for(int i = 0;i < n;i++) f[a[i]] = 0;
		for(int x = 5000;x >= 1;x--)
		{
			for(int i = 0;i < n;i++)
			{
				int y = a[i];
				f[g[x][y]] = min(f[x] + 1,f[g[x][y]]);
			}
		}
		cout << f[1] + n - 1 << '\n';
	}
	
}

int main()
{
	for(int i = 0;i <= 5000;i++)
		g[i][0] = g[0][i] = g[i][i] = i;
	for(int i = 1;i <= 5000;i++)
	{
		for(int j = 1;j < i;j++)
		{
			g[i][j] = g[j][i] = g[j][i % j];
		}
	}
	int t;
	cin >> t;
	while(t--) solve();
}