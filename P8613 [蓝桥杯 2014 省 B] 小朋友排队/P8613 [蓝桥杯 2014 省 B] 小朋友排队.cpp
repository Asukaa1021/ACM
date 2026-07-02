#include<bits/stdc++.h>
using namespace std;
#define int long long
int lowbit(int x)
{
	return x & (-x);
}
int a[100005],b[100005],n,sum[100005],t[100005];//shu zhuang shu zu;

void add(int x,int y)
{
	while(x <= 100005)
	{
		t[x] += y;
		x += lowbit(x);
	}
}

int query(int x)
{
	int sum = 0;
	while(x)
	{
		sum += t[x];
		x -= lowbit(x);
	}
	return sum;
}

signed main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1,b + 1 + n);
	int blen = unique(b + 1,b + 1 + n) - b;
	for(int i = 1;i <= n;i++)
	{
		int pos = lower_bound(b + 1,b + 1 + blen,a[i]) - b;
		a[i] = pos;
	}
	for(int i = 1;i <= n;i++)
	{
		add(a[i],1);
		sum[i] += (i - query(a[i]));
	}
	memset(t,0,sizeof t);
	for(int i = n;i >= 1;i--)
	{
		add(a[i],1);
		sum[i] += query(a[i] - 1);
	}
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		ans += (1 + sum[i]) * sum[i] / 2;
	}
	cout << ans << endl;
}
