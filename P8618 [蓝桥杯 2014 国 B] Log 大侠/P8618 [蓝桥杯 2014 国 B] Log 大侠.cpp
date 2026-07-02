#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long a[N],val[N << 2];
long long sum;
void build(int p,int l,int r)
{
	if(l == r)
	{
		val[p] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(p << 1,l,mid);
	build(p << 1 | 1,mid + 1,r);
	val[p] = max(val[p << 1],val[p << 1 | 1]);
}

void Log(int p,int l,int r,int L,int R)
{
	if(val[p] <= 2) return;
	if(l == r)
	{
		int L = (int)(log2(val[p]) + 1);
		sum -= val[p] - L;
		val[p] = L;
		return;
	}
	int mid = l + r >> 1;
	if(L <= mid) Log(p << 1,l,mid,L,R);
	if(mid < R) Log(p << 1 | 1,mid + 1,r,L,R);
	val[p] = max(val[p << 1],val[p << 1 | 1]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	build(1,1,n);
	while(m--)
	{
		int L,R;
		cin >> L >> R;
		Log(1,1,n,L,R);
		cout << sum << endl;
	}
}