#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int num[110][110];char s[110];
long long dp[110][110][110],sum[110][110];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%s",s + 1);
		for(int j = 1;j <= m;j++)
			num[i][j] = num[i][j-1] + (s[j] == 'X');
	}
	long long ans = 1;
	for(int l = 1;l <= m;l++)
		for(int r = l;r <= m;r++){
			dp[n][l][r] = (num[n][r] - num[n][l-1] == 0);
			ans = (ans + dp[n][l][r]) % mod;
		}
	for(int i = n - 1;i >= 1;i--){
		for(int l = 1;l <= m;l++)
			for(int r = 1;r <= m;r++)
				sum[l][r] = (dp[i+1][l][r] + sum[l][r-1] + sum[l-1][r] - sum[l-1][r-1]) % mod;
		for(int l = 1;l <= m;l++)
			for(int r = l;r <= m;r++) 
				if(num[i][r] - num[i][l-1] == 0)
				{
					dp[i][l][r] = (sum[l][m] - sum[l][r-1]) % mod;
					ans = (ans + dp[i][l][r]) % mod;
				}
	}
	printf("%lld",(ans+mod)%mod);
	return 0;
}