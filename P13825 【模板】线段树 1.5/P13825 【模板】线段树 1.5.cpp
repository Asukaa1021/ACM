#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N = 1e5 + 5;
int n,m,idx,lc[N * 120],rc[N * 120],lazy[N * 120],sum[N * 120],rt;

int preSum(int x,int y)
{
	return (y - x + 1) * (y + x) / 2;
}

void pushdown(int x,int l,int r,int mid)
{
	if(lazy[x])
	{
		if(!lc[x]) lc[x] = ++idx;
		if(!rc[x]) rc[x] = ++idx;
		sum[lc[x]] += (mid - l + 1) * lazy[x];
		sum[rc[x]] += (r - mid) * lazy[x];
		lazy[lc[x]] += lazy[x];
		lazy[rc[x]] += lazy[x];
		lazy[x] = 0;
	}
}

void update(int &x,int l,int r,int ql,int qr,int k)
{
	if(!x) x = ++idx;
	if(ql <= l && r <= qr)
	{
		sum[x] += (r - l + 1) * k;
		lazy[x] += k;
		return;
	}
	int mid = l + r >> 1;
	pushdown(x,l,r,mid);
	if(ql <= mid) update(lc[x],l,mid,ql,qr,k);
	if(qr > mid) update(rc[x],mid + 1,r,ql,qr,k);
	sum[x] = sum[lc[x]] + sum[rc[x]];
}

int query(int x,int l,int r,int ql,int qr)
{
	if(ql <= l && r <= qr)
	{
		return sum[x];
	}
	int mid = l + r >> 1;
	int ans = 0;
	pushdown(x,l,r,mid);
	if(ql <= mid) ans += query(lc[x],l,mid,ql,qr);
	if(mid < qr) ans += query(rc[x],mid + 1,r,ql,qr);
	return ans;
}

signed main()
{
	cin >> n >> m;
	while(m--)
	{
		int op,x,y;
		cin >> op >> x >> y;
		if(op == 1)
		{
			long long k;
			cin >> k;
			update(rt,1,n,x,y,k);
		}
		else
		{
			cout << query(rt,1,n,x,y) + preSum(x,y)<< endl;
		}
	}
}