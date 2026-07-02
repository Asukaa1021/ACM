#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[300005],_rank[300005];

stack<int> stk;
int find(int x)
{
	if(fa[x] == x) return x;
	return find(fa[x]);
}

void unite(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx == fy)
	{
		stk.push(0);
		return;
	}
	if(_rank[fx] >= _rank[fy])
	{
		stk.push(fy);
		fa[fy] = fx;
		_rank[fy]++;
	}
	else
	{
		stk.push(fx);
		fa[fx] = fy;
		_rank[fx]++;
	}
}

void runite()
{
	int x = stk.top();
	stk.pop();
	fa[x] = x;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) fa[i] = i;
	
	while(m--)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			int a,b;
			cin >> a >> b;
			unite(a,b);
		}
		else if(op == 2)
		{
			if(stk.empty()) continue;
			runite();
		}
		else
		{
			int a,b;
			cin >> a >> b;
			int faa = find(a);
			int fbb = find(b);
			if(faa == fbb) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
}
