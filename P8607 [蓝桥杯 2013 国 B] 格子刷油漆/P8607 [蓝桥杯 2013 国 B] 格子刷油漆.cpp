#include<bits/stdc++.h>
#define int long long
using namespace std;
const int modd = 1000000007;

int a[1005],b[1005];
int ans = 0;
signed main()
{
	int n;
	cin >> n;
	a[1] = 1,a[2] = 6;
	b[1] = 1,b[2] = 2;
	if(n == 1)
	{
		cout << 2 << endl;
		return 0;
	}
	int ans = 0;
	for(int i = 3;i <= n;i++)
	{
		b[i] = b[i - 1] * 2 % modd;
		a[i] = a[i - 1] * 2 % modd + a[i - 2] * 4 % modd + b[i] % modd;
	}
	for(int i = 2;i < n;i++)
	{
		int l = i - 1;
		int r = n - i;
		ans = (ans + 4 * b[l + 1] % modd * a[r] % modd) % modd;
		ans = (ans + 4 * a[l] % modd * b[r + 1] % modd) % modd;
	}
	ans += 4 * a[n] % modd;
	ans %= modd;
	cout << ans << endl;
}
