#include<bits/stdc++.h>
using namespace std;
int n,q;
int Z[1000005];
int c[1000005][55];
void update(int x,int y,int t)
{
	c[x][y] = t;
	if(x == 0 || y == 0) return;
	update(x / 2,y - 1,t);
}

inline int dis(int x,int y)
{
	if(x < y) swap(x,y);
	int cnt = 0;
	while(x != y)
	{
		cnt++;
		x /= 2;
	}
	return cnt;
}

int query(int x)
{
	int maxn = 0;
	int fa = x;
	int step = 0;
	while(fa > 0)
	{
		for(int d = step;d <= 54;d++)
		{
			maxn = max(maxn,c[fa][d]);
		}
		step++;
		fa /= 2;
	}
	return maxn;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t = 0;
	cin >> n >> q;

	while(q--)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			t++;
			int x,y,z;
			cin >> x >> y >> Z[t];
			y = min(y,54);
			update(x,y,t);
		}
		else
		{
			int que;
			cin >> que;
			cout << Z[query(que)] << endl;
		}
	}
}
