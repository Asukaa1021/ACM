#include<bits/stdc++.h>
using namespace std;

long long sum[35][35];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	sum[1][1] = 1;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			if(i == 1 && j == 1) continue;
			if(i % 2 == 0 && j % 2 == 0) continue;
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j];
		}
	}
	cout << sum[n][m] << endl;
}