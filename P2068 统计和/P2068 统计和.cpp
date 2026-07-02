#include<bits/stdc++.h>
using namespace std;
#define lp p << 1
#define rp p << 1 | 1
#define int long long
int n,t;

struct node
{
	int l,r;
	int sum;
}a[400005];

void build(int p,int l,int r)
{
	a[p].l = l;
	a[p].r = r;
	if(l == r)
	{
		return;
	}
	int mid = l + r >> 1;
	build(lp,l,mid);
	build(rp,mid + 1,r);
}

void update(int p,int x,int b)
{
	if(a[p].l == a[p].r)
	{
		a[p].sum += b;
		return;
	}
	//if(a[p].l > x || a[p].r < x) return;
	int mid = a[p].l + a[p].r >> 1;
	if(x <= mid) update(lp,x,b);
	else update(rp,x,b);
	
	a[p].sum = a[lp].sum + a[rp].sum;
}

int query(int p,int x,int y)
{
	if(x <= a[p].l && a[p].r <= y)
	{
		return a[p].sum;
	}
	if(a[p].r < x || a[p].l > y) return 0;
	int sum = 0;
	int mid = a[p].l + a[p].r >> 1;
	sum += query(lp,x,y);
	sum += query(rp,x,y);
	return sum;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> t;
	build(1,1,n);
	while(t--)
	{
		char op;
		cin >> op;
		if(op == 'x')
		{
			int a,b;
			cin >> a >> b;
			update(1,a,b);
		}
		else
		{
			int a,b;
			cin >> a >> b;
			cout << query(1,a,b) << endl;
		}
	}
}
