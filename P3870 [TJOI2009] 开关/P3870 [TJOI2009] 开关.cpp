#include<bits/stdc++.h>
#define lc p << 1
#define rc p << 1 | 1
using namespace std;
const int N = 1e5 + 5;
int n,m;
struct node
{
	int l,r,sum,lazy;
}tr[N * 4];

void build(int p,int l,int r)
{
	tr[p] = {l,r,0,0};
	if(l == r) return;
	int mid = l + r >> 1;
	if(l <= mid) build(lc,l,mid);
	if(mid < r) build(rc,mid + 1,r);
	tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void pushdown(int p)
{
	if(tr[p].lazy)
	{
		tr[lc].sum = (tr[lc].r - tr[lc].l + 1) - tr[lc].sum;
		tr[rc].sum = (tr[rc].r - tr[rc].l + 1) - tr[rc].sum;
		tr[lc].lazy = 1 - tr[lc].lazy;
		tr[rc].lazy = 1 - tr[rc].lazy;
		tr[p].lazy = 0;
	}
}

void update(int p,int x,int y)
{
	if(x <= tr[p].l && tr[p].r <= y)
	{
		tr[p].sum = (tr[p].r - tr[p].l + 1) - tr[p].sum;
		tr[p].lazy = 1 - tr[p].lazy;
		return;
	}
	int mid = tr[p].l + tr[p].r >> 1;
	pushdown(p);
	if(x <= mid) update(lc,x,y);
	if(mid < y) update(rc,x,y);
	tr[p].sum = tr[lc].sum + tr[rc].sum;
}

int query(int p,int x,int y)
{
	if(x <= tr[p].l && tr[p].r <= y) return tr[p].sum;
	int ans = 0;
	pushdown(p);
	int mid = tr[p].l + tr[p].r >> 1;
	if(x <= mid) ans += query(lc,x,y);
	if(mid < y) ans += query(rc,x,y);
	return ans;
}

int main()
{
	cin >> n >> m;
	build(1,1,n);
	while(m--)
	{
		int op,x,y;
		cin >> op >> x >> y;
		if(op == 0)
		{
			update(1,x,y);
		}
		else
		{
			cout << query(1,x,y) << endl;
		}
	}
}