#include<bits/stdc++.h>
#define lc p << 1
#define rc p << 1 | 1

using namespace std;
const long long N = 1e6 + 5;
const long long S = 1e18;
long long n,m;
long long w[N];
struct node
{
	long long l,r,m,lazy1,lazy2;
}tr[N * 4];

void build(long long p,long long l,long long r)
{
	tr[p] = {l,r,w[l],0,S};
	if(l == r) return;
	long long mid = (l + r) >> 1;
	if(l <= mid) build(lc,l,mid);
	if(mid < r) build(rc,mid + 1,r);
	tr[p].m = max(tr[lc].m , tr[rc].m);
}

void pushdown(long long p)
{
	if(tr[p].lazy2 != S)
	{
		tr[lc].m = tr[p].lazy2;
		tr[rc].m = tr[p].lazy2;
		tr[lc].lazy2 = tr[p].lazy2;
		tr[rc].lazy2 = tr[p].lazy2;
		tr[p].lazy2 = S;
		tr[p].lazy1 = 0;
		tr[lc].lazy1 = 0;
		tr[rc].lazy1 = 0;
	}
	if(tr[p].lazy1 != 0)
	{
		tr[lc].m += tr[p].lazy1;
		tr[rc].m += tr[p].lazy1;
		tr[lc].lazy1 += tr[p].lazy1;
		tr[rc].lazy1 += tr[p].lazy1;
		tr[p].lazy1 = 0;
	}
	
}

void update2(long long p,long long x,long long y,long long k)
{
	if(x <= tr[p].l && tr[p].r <= y)
	{
		tr[p].m = k;
		tr[p].lazy2 = k;
		tr[p].lazy1 = 0;
		return;
	}
	long long mid = tr[p].l + tr[p].r >> 1;
	pushdown(p);
	if(x <= mid) update2(lc,x,y,k);
	if(y > mid) update2(rc,x,y,k);
	tr[p].m = max(tr[lc].m , tr[rc].m);
}

void update1(long long p,long long x,long long y,long long k)
{
	if(x <= tr[p].l && tr[p].r <= y)
	{
		tr[p].m += k;
		tr[p].lazy1 += k;
		return;
	}
	long long mid = (tr[p].l + tr[p].r) >> 1;
	pushdown(p);
	if(x <= mid) update1(lc,x,y,k);
	if(mid < y) update1(rc,x,y,k);
	tr[p].m = max(tr[lc].m , tr[rc].m);
}

long long query(long long p,long long x,long long y)
{
	if(x <= tr[p].l && tr[p].r <= y) return tr[p].m;
	long long mid = (tr[p].l + tr[p].r) >> 1;
	long long Max = -INF;
	pushdown(p);
	if(x <= mid) Max = max(Max,query(lc,x,y));
	if(mid < y) Max = max(Max,query(rc,x,y));
	return Max;
}

int main()
{
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) scanf("%lld",&w[i]);
	build(1,1,n);
	while(m--)
	{
		long long op,x,y,k;
		scanf("%lld%lld%lld",&op,&x,&y);
		if(op == 1)
		{
			long long k;
			scanf("%lld",&k);
			update2(1,x,y,k);
		}
		else if(op == 2)
		{
			long long k;
			scanf("%lld",&k);
			update1(1,x,y,k);
		}
		else
		{
			cout << query(1,x,y) << endl;
		}
	}
}