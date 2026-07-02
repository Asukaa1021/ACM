#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n,m,to[20005],head[20005],_prev[20005],W[20005];
int listLen = 0;

inline void add(int u,int v,int w)
{
	to[++listLen] = v;
	W[listLen] = w;
	_prev[listLen] = head[u];
	head[u] = listLen;
}

int main()
{
	cin >> n >> m;
	memset(_prev,-1,sizeof _prev);
	memset(head,-1,sizeof head);
	for(int i = 1;i <= m;i++)
	{
		int b,e,t;
		cin >> b >> e >> t;
		add(b - 1,e,t);
	}
	for(int i = 1;i <= n;i++)
	{
		add(i - 1,i,0);
		add(i,i - 1,-1);
	}
	vector<int> d(n + 1,-INF);
	vector<bool> inq(n + 1);
	d[0] = 0;
	inq[0] = true;
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int u = q.front();q.pop();
		inq[u] = false;
		for(int i = head[u];i != -1;i = _prev[i])
		{
			int v = to[i];
			int w = W[i];
			if(d[v] < d[u] + w)
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
	cout << d[n] << endl;
}
