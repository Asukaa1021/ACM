#include<bits/stdc++.h>
using namespace std;

int a[100005];
int preSum[100005];
bool pd[100005];
int main()
{
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	int n,m;long long ans = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] % m == 0)
		{
			preSum[i] = preSum[i - 1];
			pd[i] = true;
		 } 
		else
		{
			preSum[i] = preSum[i - 1] + 1;
			pd[i] = false;
		 } 
	} 
	long long j = 2;
	for(long long i = 1;i <= n && i <= j;i++)
	{
		while(j <= n && preSum[j] - preSum[i - 1] <= 1)
		{
			j++;
		}
		ans += j - i - 1;
	}
	cout << ans << endl;
}