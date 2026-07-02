#include<bits/stdc++.h>
#define lc p<<1
#define rc p<<1|1

using namespace std;
const int N = 1e5 + 5;
int n,m;
long long Mod;
long long w[N];
struct node
{
	int l,r;
	long long sum,lazy,lazy2;
}tree[4 * N + 3];

void build(int p,int l,int r)
{
	tree[p] = {l,r,w[l],0,1};
	if(l == r) return;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid + 1,r);
	tree[p].sum = tree[lc].sum + tree[rc].sum;
}

void pushdown(int p)
{
	if(tree[p].lazy2 != 1)
	{
		tree[lc].sum = (tree[lc].sum * tree[p].lazy2) % Mod;
		tree[rc].sum = (tree[rc].sum * tree[p].lazy2) % Mod;
		tree[lc].lazy2 = (tree[lc].lazy2 * tree[p].lazy2) % Mod;
		tree[rc].lazy2 = (tree[rc].lazy2 * tree[p].lazy2) % Mod;
		tree[lc].lazy = (tree[lc].lazy * tree[p].lazy2) % Mod;
		tree[rc].lazy = (tree[rc].lazy * tree[p].lazy2) % Mod;
		tree[p].lazy2 = 1;
	}
	if(tree[p].lazy)
	{
		tree[lc].sum += tree[p].lazy * (tree[lc].r - tree[lc].l + 1);
		tree[lc].sum = tree[lc].sum % Mod;
		tree[rc].sum += tree[p].lazy * (tree[rc].r - tree[rc].l + 1);
		tree[rc].sum = tree[rc].sum % Mod;
		tree[lc].lazy = (tree[lc].lazy + tree[p].lazy) % Mod;
		tree[rc].lazy = (tree[rc].lazy + tree[p].lazy) % Mod;
		tree[p].lazy = 0;
	}
}



void update(int p,int x,int y,long long k)
{
	if(x <= tree[p].l && tree[p].r <= y)
	{
		tree[p].sum += (tree[p].r - tree[p].l + 1) * k;
		tree[p].sum = tree[p].sum % Mod;
		tree[p].lazy += k;
		tree[p].lazy %= Mod;
		return;
	}
	int mid = (tree[p].l + tree[p].r) / 2;
	pushdown(p);
	if(x <= mid) update(lc,x,y,k);
	if(y > mid) update(rc,x,y,k);
	tree[p].sum = (tree[lc].sum + tree[rc].sum) % Mod;
}

void update2(int p ,int x,int y,long long k)
{
	if(x <= tree[p].l && tree[p].r <= y)
	{
		tree[p].sum *= k;
		tree[p].sum = tree[p].sum % Mod;
		tree[p].lazy2 *= k;
		tree[p].lazy2 %= Mod;
		tree[p].lazy *= k;
		tree[p].lazy %= Mod;
		return;
	}
	int mid = (tree[p].l + tree[p].r) / 2;
	pushdown(p);
	if(x <= mid) update2(lc,x,y,k);
	if(y > mid) update2(rc,x,y,k);
	tree[p].sum = (tree[lc].sum + tree[rc].sum) % Mod;
}

long long query(int p,int x,int y)
{
	if(x <= tree[p].l && tree[p].r <= y)
	{
		return tree[p].sum;
	}
	int mid = (tree[p].l + tree[p].r) / 2;
	pushdown(p);
	long long sum = 0;
	if(x <= mid) sum += query(lc,x,y);
	if(y > mid) sum += query(rc,x,y);
	return sum % Mod;
}

int main()
{
	cin >> n >> m >> Mod;
	for(int i = 1;i <= n;i++) 
	{
		cin >> w[i];
		w[i] = w[i] % Mod;
	}
	build(1,1,n);
	while(m--)
	{
		int op,x,y;
		cin >> op >> x >> y;
		if(op == 2)
		{
			long long k;
			cin >> k;
			k = k % Mod;
			update(1,x,y,k);
		}
		else if(op == 1)
		{
			long long k;
			cin >> k;
			k = k % Mod;
			update2(1,x,y,k);
		}
		else
		{
			cout << query(1,x,y) << endl;
		}
	}
}