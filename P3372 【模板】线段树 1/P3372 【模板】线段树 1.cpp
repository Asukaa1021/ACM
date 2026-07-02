#include<bits/stdc++.h>
#define lc p<<1 
#define rc p<<1|1 
using namespace std;
const int N = 1e5;
int n,m;
unsigned long long w[N + 2];
struct node
{
	int l,r;
	unsigned long long sum,lazy;
}tree[4 * N + 3];

void build(int p,int l,int r)
{
	tree[p] = {l,r,w[l],0};
	if(l == r) return;
	int M = (l + r)/2;
	build(lc,l,M);
	build(rc,M + 1,r);
	tree[p].sum = tree[lc].sum + tree[rc].sum;
}

void pushdown(int p)
{
	if(tree[p].lazy)
	{
		tree[lc].sum += (tree[lc].r - tree[lc].l + 1) * tree[p].lazy;
		tree[rc].sum += (tree[rc].r - tree[rc].l + 1) * tree[p].lazy;
		tree[lc].lazy += tree[p].lazy;
		tree[rc].lazy += tree[p].lazy;
		tree[p].lazy = 0;
	}
}

void update2(int p,int x,int y,unsigned long long k)
{
	if(x <= tree[p].l && tree[p].r <= y)
	{
		tree[p].sum += (tree[p].r - tree[p].l + 1) * k;
		tree[p].lazy += k;
		return;
	}
	int mid = (tree[p].l + tree[p].r) / 2;
	pushdown(p);
	if(x <= mid) update2(lc,x,y,k);
	if(y > mid) update2(rc,x,y,k);
	tree[p].sum = tree[lc].sum + tree[rc].sum;
}

void update1(int p,int x,unsigned long long k)
{
	if(tree[p].l == x && x == tree[p].r)
	{
		tree[p].sum += k;
		return;
	}
	int M = (tree[p].l + tree[p].r) / 2;
	if(M > x) update1(rc,x,k);
	if(M <= x) update1(lc,x,k);
	tree[p].sum = tree[lc].sum + tree[rc].sum;
}

unsigned long long query(int p,int x,int y)
{
	if(x <= tree[p].l && tree[p].r <= y)
	{
		return tree[p].sum;
	}
	int mid = (tree[p].l + tree[p].r) / 2;
	unsigned long long sum = 0;
	pushdown(p);
	if(x <= mid) sum += query(lc,x,y);
	if(y > mid) sum += query(rc,x,y);
	return sum;
}

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> w[i];
	build(1,1,n);
	while(m--)
	{
		int op,x,y;
		cin >> op >> x >> y;
		if(op == 1)
		{
			unsigned long long k;
			cin >> k;
			update2(1,x,y,k);
		}
		else
		{
			cout << query(1,x,y) << endl;
		}
	}
}