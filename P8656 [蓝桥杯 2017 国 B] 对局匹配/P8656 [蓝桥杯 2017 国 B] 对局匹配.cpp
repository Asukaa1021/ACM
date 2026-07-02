#include<bits/stdc++.h>
using namespace std;

int cnt[100005],dp[100005][2],vis[100005];
int ans = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,k;
	cin >> n >> k;
	
	for(int i = 1;i <= n;i++)
	{
		int num;
		cin >> num;
		cnt[num]++;
		if(!vis[num]) ans++;
		vis[num] = true;
	}
	if(k != 0)
	{
		ans = 0;
		for(int i = 0;i <= k - 1;i++)
		{
			int Max = 0;
			dp[i][1] = cnt[i];
			for(int j = i + k;j <= 100000;j += k)
			{
				dp[j][1] = dp[j - k][0] + cnt[j];
				dp[j][0] = max(dp[j - k][0],dp[j - k][1]);
				Max = max(dp[j][1],Max);
				Max = max(dp[j][0],Max);
			}
			ans += Max;
		}
		cout << ans << endl;
	}
	else
	{
		cout << ans << endl;
	}
}
