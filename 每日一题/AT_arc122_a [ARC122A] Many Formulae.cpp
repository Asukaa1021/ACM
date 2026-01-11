#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n;
long long a[100005];
long long dt[100005][2];
long long sum[100005][2];
int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	dt[1][0] = 0;
	dt[1][1] = 1;
	sum[1][1] = a[1];
	for(int i = 2;i <= n;i++)
	{
		dt[i][1] = dt[i - 1][0] % mod + dt[i - 1][1] % mod;
		dt[i][0] = dt[i - 1][1] % mod;
		sum[i][1] = dt[i][1] * a[i] % mod + sum[i - 1][1] % mod + sum[i - 1][0] % mod;
		sum[i][0] = mod - dt[i][0] * a[i] % mod + sum[i - 1][1] % mod;
	}
	
	cout << (sum[n][1] % mod + mod + sum[n][0] % mod) % mod << endl;
}