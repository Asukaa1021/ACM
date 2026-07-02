#include<bits/stdc++.h>
using namespace std;
const int N = 1000001;
int n,m;
int po[2000005];
int sum = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		int p;
		cin >> p;
		if(p == 0) sum++;
		po[p + N]++; 
	}
	po[N] = 0;
	for(int i = N - 1;i >= 0;i--)
	{
		if(i != N - 1) po[i] += po[i + 1];
	}
	for(int i = N + 1;i <= N * 2 + 1;i++)
	{
		if(i != N + 1) po[i] += po[i - 1];
	}
	int ans1 = 0,ans2 = 0;
	for(int i = 0;i <= m / 2;i++)
	{
		if(N - (m - i * 2) < 0) continue;
		int tot = po[i + N] + po[N - (m - i * 2)];
		ans1 = max(ans1,tot);
	}
	for(int i = 0;i <= m / 2;i++)
	{
		if(N + (m - i * 2) > 2000004) continue;
		int tot = po[N - i] + po[N + (m - i * 2)];
		ans2 = max(ans2,tot);
	}
	sum += max(ans1,ans2);
	cout << sum << endl;
}