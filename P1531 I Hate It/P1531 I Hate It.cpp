#include<bits/stdc++.h>
using namespace std;
#define lp p << 1
#define rp p << 1 | 1
int n,m;
int num[200005];
struct node
{
	int l,r;
	int high;
}a[800005];

void pushup(int p)
{
	a[p].high = max(a[lp].high,a[rp].high);
}

void build(int p,int l,int r)
{
	a[p].l = l;
	a[p].r = r;
	if(l == r)
	{
		a[p].high = num[l];
		return;
	}
	int mid = l + r >> 1;
	build(lp,l,mid);
	build(rp,mid + 1,r);
	
	pushup(p);
}

void update(int p,int x,int b)
{
	if(a[p].l == a[p].r)
	{
		a[p].high = max(a[p].high,b);
		return;
	}
	int mid = a[p].l + a[p].r >> 1;

	if(x <= mid) update(lp,x,b);
	else update(rp,x,b);
	
	pushup(p);
}


int query(int p,int x,int y)
{
	if(x <= a[p].l && a[p].r <= y) return a[p].high;
	if(a[p].r < x || a[p].l > y) return -1;
	
	int lres = query(lp,x,y);
	int rres = query(rp,x,y);
	
	return max(lres,rres);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> num[i];
	build(1,1,n);
	
	while(m--)
	{
		char op;
		cin >> op;
		if(op == 'Q')
		{
			int x,y;
			cin >> x >> y;
			cout << query(1,x,y) << endl;
		}
		else
		{
			int x,b;
			cin >> x >> b;
			update(1,x,b);
		}
	}
}
