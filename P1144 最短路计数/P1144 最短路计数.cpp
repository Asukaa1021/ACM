#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4000005;
int n,m,cnt_edge;
int to[MAXN],Next[MAXN],head[MAXN];

void add(int a,int b)
{
	to[++cnt_edge] = b;
	Next[cnt_edge] = head[a];
	head[a] = cnt_edge;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	cin >> n >> m;
	
	memset(Next,-1,sizeof Next);
	memset(head,-1,sizeof head);
	
	for(int i = 1;i <= m;i++)
	{
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	vector<int> dis(n + 1,-1);
	vector<int> cnt(n + 1,0);
	dis[1] = 0;
	cnt[1] = 1;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int i = head[u];i != -1;i = Next[i])
		{
			int v = to[i];
			if(dis[v] == -1)
			{
				cnt[v] = cnt[u];
				dis[v] = dis[u] + 1;
				q.push(v);
			}
			else if(dis[v] == dis[u] + 1)
			{
				cnt[v] = (cnt[v] + cnt[u]) % 100003;
			}
		}
	}
	for(int i = 1;i <= n;i++) cout << cnt[i] << endl;
}
