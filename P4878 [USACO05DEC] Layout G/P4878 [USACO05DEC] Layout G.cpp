#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e15;
int n,ml,md,to[2000005],nxt[2000005],head[2000005],W[2000005];
int len = 0;

inline void add(int u,int v,int w)
{
	to[++len] = v;
	W[len] = w;
	nxt[len] = head[u];
	head[u] = len;
}

signed main()
{
	cin >> n >> ml >> md;
	memset(nxt,-1,sizeof nxt);
	memset(head,-1,sizeof head);
	for(int i = 1;i <= ml;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
	}
	for(int i = 1;i <= md;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		add(v,u,-w);
	}
	for(int i = 1;i <= n;i++)
	{
		add(i + 1,i,0);
	}
/*	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(i == j) continue;
			add(i,j,-1);
		}
	}*/
	vector<bool> inq(n + 1);
	vector<int> d(n + 1,INF);
	vector<int> cnt(n + 1);
	queue<int> q;
	d[1] = 0;
	for(int i = 1;i <= n;i++)
	{
		q.push(i);
		inq[i] = true;
	}
	bool flg = false;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = false;
		cnt[u]++;
		if(cnt[u] >= n + 1)
		{
			flg = true;
			break;
		}
		for(int i = head[u];i != -1;i = nxt[i])
		{
			int v = to[i];
			int w = W[i];
			if(d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				if(!inq[v])
				{
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
	if(!flg)
	{
		if(d[n] == INF) cout << -2 << endl;
		else cout << d[n] << endl;
	}	
	else
	{
		cout << -1 << endl;
	}
}
