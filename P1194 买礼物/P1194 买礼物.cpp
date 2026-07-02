#include<bits/stdc++.h>
using namespace std;
int a,b;
int fa[505];
struct Edge
{
	int u,v,w;
	bool operator<(const  Edge &b) const {
		return w < b.w;
	}
};

int find(int x)
{
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

void unite(int x,int y)
{
	int xx = find(x);
	int yy = find(y);
	if(xx == yy) return;
	fa[xx] = yy;
}

vector<Edge> e;
int main()
{
	cin >> a >> b;
	for(int i = 1;i <= b;i++)
	{
		for(int j = 1;j <= b;j++)
		{
			int w;
			cin >> w;
			if(i != j && w != 0) e.push_back({i,j,w});
		}
	}
	for(int i = 1;i <= b;i++)
	{
		e.push_back({0,i,a});
	}
	int ans = 0;
	sort(e.begin(),e.end());
	queue<Edge> q;
	for(int i = 0;i < e.size();i++)	q.push(e[i]);
	for(int i = 0;i <= b;i++) fa[i] = i;
	int cnt = 0;
	while(cnt < b)
	{
		auto [u,v,w] = q.front();
		q.pop();
		int uu = find(u);
		int vv = find(v);
		if(uu == vv) continue;
		else
		{
			unite(u,v);
			ans += w;
			cnt++;
		}
	}
	cout << ans << endl;
}
