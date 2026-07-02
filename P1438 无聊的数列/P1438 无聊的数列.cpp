#include<bits/stdc++.h>
#define lp p << 1
#define rp p << 1 | 1
#define int long long
using namespace std;

int n,m;
int num[100005];
struct node
{
	int l,r;
	int sum,lazy;
}a[400005];

void build(int p,int l,int r)
{
	a[p].l = l;
	a[p].r = r;
	if(l == r)
	{
		a[p].sum = num[l];
		return;
	}
	int mid = l + r >> 1;
	build(lp,l,mid);
	build(rp,mid + 1,r);
	
	a[p].sum = a[lp].sum + a[rp].sum;
}
void pushdown(int p)
{
	if(a[p].lazy != 0)
	{
		a[lp].lazy += a[p].lazy;
		a[rp].lazy += a[p].lazy;
		a[lp].sum += (a[lp].r - a[lp].l + 1) * a[p].lazy;
		a[rp].sum += (a[rp].r - a[rp].l + 1) * a[p].lazy;
		a[p].lazy = 0;
	}
}
void update(int p,int l,int r,int b)
{
	if(a[p].l >= l && a[p].r <= r)
	{
		a[p].sum += (a[p].r - a[p].l + 1) * b;
		a[p].lazy += b;
		return;
	}
	int mid = a[p].l + a[p].r >> 1;
	if(l <= mid) update(lp,l,r,b);
	if(mid + 1 <= r) update(rp,l,r,b);
	pushdown(p);
	a[p].sum = a[lp].sum + a[rp].sum;
}

int query(int p,int x,int y)
{
	pushdown(p);
	if(x <= a[p].l && a[p].r <= y)
	{
		return a[p].sum;
	}
	if(a[p].l > y || a[p].r < x) return 0;
	return query(lp,x,y) + query(rp,x,y);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) 
	{
		cin >> num[i];
	}
	num[n + 1] = -num[n];
	for(int i = n;i >= 1;i--)
	{
		num[i] = num[i] - num[i - 1];
	}
	build(1,1,n + 1);
	while(m--)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			int l,r,k,d;
			cin >> l >> r >> k >> d;
			update(1,l,l,k);
			update(1,l + 1,r,d);
			update(1,r + 1,r + 1,-(k + (r - l) * d));
		}
		else
		{
			int pos;
			cin >> pos;
			cout << query(1,1,pos) << endl;
		}
	}
}
