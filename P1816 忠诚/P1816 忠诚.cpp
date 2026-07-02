#include<bits/stdc++.h>
using namespace std;
#define lp p << 1
#define rp p << 1 | 1
struct node
{
	int l,r;
	int minn;
}a[400005];

int num[100005];
int m,n;

void build(int p,int l,int r)
{
	a[p].l = l;
	a[p].r = r;
	if(l == r)
	{
		a[p].minn = num[l];
		return;
	}
	int mid = l + r >> 1;
	build(lp,l,mid);
	build(rp,mid + 1,r);
	
	a[p].minn = min(a[lp].minn,a[rp].minn);
}

int query(int p,int l,int r)
{
	if(a[p].l > r || a[p].r < l)
	{
		return INT_MAX;
	}
	if(l <= a[p].l && a[p].r <= r) return a[p].minn;
	
	int lres = query(lp,l,r);
	int rres = query(rp,l,r);
	
	return min(lres,rres);
}

int main()
{
	cin >> m >> n;
	for(int i = 1;i <= m;i++)
	{
		cin >> num[i];
	}
	build(1,1,m);
	while(n--)
	{
		int x,y;
		cin >> x >> y;
		cout << query(1,x,y);
		if(n != 0) cout << " ";
	}
}
