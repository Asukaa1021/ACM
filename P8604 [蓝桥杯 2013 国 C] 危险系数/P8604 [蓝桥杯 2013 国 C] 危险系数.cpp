#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,q1,q2;
int head[4005],nxt[4005],to[4005],len = 0,_rank[2005];
int fa[2005];

int find(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void unite(int x,int y)
{
	int fax = find(x);
	int fay = find(y);
	if(fax == fay) return;
	if(_rank[fax] >= _rank[fay])
	{
		fa[fax] = fay;
		_rank[fay]++;
	}
	else
	{
		fa[fay] = fax;
		_rank[fax]++;
	}
}

void add(int u,int v)
{
	to[++len] = v;
	nxt[len] = head[u];
	head[u] = len;
	to[++len] = u;
	nxt[len] = head[v];
	head[v] = len;
}

bool bfs(int ban)
{
	vector<bool> vis(n + 1);
	queue<int> q;
	q.push(q1);
	vis[q1] = true;
	while(q.size())
	{
		int u = q.front();q.pop();
		vis[u] = true;
		for(int i = head[u];i != -1;i = nxt[i])
		{
			int v = to[i];
			if(vis[v] || v == ban) continue;
			if(v == q2) return false;
			q.push(v);
			vis[v] = true;
		}
	}
	return true;
}

int main()
{
	cin >> n >> m;
	memset(nxt,-1,sizeof nxt);
	for(int i = 1;i <= n;i++) fa[i] = i;
	for(int i = 1;i <= m;i++)
	{
		int u,v;
		cin >> u >> v;
		unite(u,v);
		add(u,v);
	}
	cin >> q1 >> q2;
	if(find(q1) != find(q2))
	{
		cout << "-1" << endl;
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			if(i != q1 && i != q2 && bfs(i)) cnt++;
		}
		cout << cnt << endl;
	}
}
