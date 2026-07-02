#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
long long n,m;
long long vis[7][7];

void mul(long long ans[][7], long long a[][7], long long b[][7]) {
	long long t[7][7] = {
		0
	};
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			for (int k = 1; k <= 6; k++)
				t[i][j] = (t[i][j] + a[i][k] * b[k][j]) % mod;
		}
	}
	memcpy(ans, t, sizeof t);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= 6;i++)
	{
		for(int j = 1;j <= 6;j++)
		{
			vis[i][j] = 4;
		}
	}
	while(m--)
	{
		int x,y;
		cin >> x >> y;
		vis[x][y] = vis[y][x] = 0;
	}
	long long t[7][7] = {
		{0, 0, 0, 0, 0, 0, 0},
		{0, vis[1][4], vis[1][5], vis[1][6], vis[1][1], vis[1][2], vis[1][3]},
		{0, vis[2][4], vis[2][5], vis[2][6], vis[2][1], vis[2][2], vis[2][3]},
		{0, vis[3][4], vis[3][5], vis[3][6], vis[3][1], vis[3][2], vis[3][3]},
		{0, vis[4][4], vis[4][5], vis[4][6], vis[4][1], vis[4][2], vis[4][3]},
		{0, vis[5][4], vis[5][5], vis[5][6], vis[5][1], vis[5][2], vis[5][3]},
		{0, vis[6][4], vis[6][5], vis[6][6], vis[6][1], vis[6][2], vis[6][3]},
	};
	
	long long ans[7][7] = {
		{0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 1},
	};
	n--;
	while(n)
	{
		if(n & 1) mul(ans,ans,t);
		n >>= 1;
		mul(t,t,t);
	}
	long long sum = 0;
	for(int i = 1;i <= 6;i++)
	{
		for(int j = 1;j <= 6;j++)
		{
			sum = (sum + ans[i][j] * 4) % mod;
		}
	}
	cout << sum << endl;
}