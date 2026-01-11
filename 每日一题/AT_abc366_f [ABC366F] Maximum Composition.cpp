#include<bits/stdc++.h>
using namespace std;

int n,k;
struct node
{
	unsigned long long a,b;
}p[200005];

unsigned long long dp[11][200005];
bool vis[200005];

bool cmp(node a,node b)
{
	return a.b * (b.a - 1) > b.b * (a.a - 1);
}

int main()
{
	cin >> n >> k;
	dp[0][0] = 1;
	//dp[0][1] = 1;
	//dp[1][0] = 1;
	for(int i = 1;i <= n;i++) cin >> p[i].a >> p[i].b;
	sort(p + 1,p + 1 + n,cmp);
	for(int i = 1;i <= n;i++) dp[0][i] = 1;
	
	for(int i = 1;i <= k;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			dp[i][j] = max(dp[i - 1][j - 1] * p[j].a + p[j].b,dp[i][j - 1]);
		}
	}
	cout << dp[k][n] << endl;
}