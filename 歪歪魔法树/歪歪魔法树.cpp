#include<bits/stdc++.h>
#define int long long
using namespace std;
const int modd = 998244353;
int head[200005];
int nxt[200005];
int to[200005];
int a[200005];
int sum[200005];
int q[200005];
int len = 0;
int tot;
int n;
int ex_gcd(int a,int b,int &x,int &y)
{
	if(b == 0)
	{
		x = 1,y = 0;
		return a;
	}
	int d = ex_gcd(b,a % b,y,x);
	y -= a / b * x;
	return d;
}

void add(int u,int v)
{
	nxt[++len] = head[u];
	to[len] = v;
	head[u] = len;
	nxt[++len] = head[v];
	to[len] = u;
	head[v] = len;
	q[u]++,q[v]++;
}

void trv(int fa,int u)
{
	vector<int> list;
	sum[u] = a[u];
	if(q[u] == 1 && fa != -1) return;
	for(int i = head[u];i != -1;i = nxt[i])
	{
		int v = to[i];
		if(v == fa) continue;
		trv(u,v);
		sum[u] = sum[u] + sum[v] % modd;
		sum[u] %= modd;
		list.push_back(sum[v]);
	}
	list.push_back(a[u]);
	if(list.size() >= 3)
	{
		int aa1 = 0,aa2 = 0,aa3 = 0;
		for(int i = 0;i < list.size();i++)
		{
			aa1 = aa1 + list[i] % modd;
			aa1 %= modd;
			aa2 = aa2 + list[i] % modd * list[i] % modd;
			aa2 %= modd;
			aa3 = aa3 + list[i] % modd * list[i] % modd * list[i] % modd;
			aa3 %= modd;
		}
		int x,y;
		ex_gcd(6,modd,x,y);
		tot = tot % modd
		 + ((aa1 * aa1 % modd * aa1 % modd + 2 * aa3 % modd - 3 * aa1 * aa2 % modd) % modd + modd) % modd
		  * (x % modd + modd) % modd;
		tot %= modd;
	//	cout << "?" << tot << " " << fa << " " << u << endl;
	//	for(int i = 1;i <= n;i++) cout << sum[i] << endl;
	}
}

void solve()
{
	
	cin >> n;
	len = 0;
	tot = 0;
	memset(head,-1,sizeof head);
	memset(nxt,-1,sizeof nxt);
	memset(sum,0,sizeof sum);
	memset(q,0,sizeof q);
	memset(sum,0,sizeof sum);
	for(int i = 1;i <= n - 1;i++)
	{
		int u,v;
		cin >> u >> v;
		add(u,v);
	}
	for(int i = 1;i <= n;i++) cin >> a[i];
	trv(-1,1);
	cout << tot << endl;
	//for(int i = 1;i <= n;i++) cout << sum[i] << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}
