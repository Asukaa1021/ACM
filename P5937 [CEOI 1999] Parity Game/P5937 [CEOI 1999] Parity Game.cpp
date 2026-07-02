#include<bits/stdc++.h>
using namespace std;

vector<int> a,b,fa,rank_;
vector<string> e;
vector<int> d;
unordered_map<int,int> mp;
int len = 0;
int get(int x)
{
	if(mp.count(x) == 0) mp[x] = ++len;
	return mp[x];
}

int find(int x)
{
	if(x == fa[x]) return x;
	else return find(fa[x]);
}

void unite(int x,int y)
{
	int rtx = find(x);
	int rty = find(y);
	if(rank_[x] > rank_[y])
	{
		fa[y] = x;
	}
	else if(rank_[x] < rank_[y])
	{
		fa[x] = y;
	}
	else
	{
		fa[x] = y;
		rank_[x]++;
	}
}

int main()
{
	int n;
	int m;
	
	cin >> n >> m;
	int res = m;
	d.resize(m + 1);
//	b.resize(m + 1);
//	e.resize(m + 1);
	fa.resize(2 * m + 2);
//	rank_.resize(2 * m + 2);
	for(int i = 1;i <= 2 * m;i++) fa[i] = i;
	for(int i = 1;i <= m;i++)
	{
		int x,y;
		string op;
	//	cin >> a[i] >> b[i] >> e[i];
		cin >> x >> y >> op;
		x = get(x - 1);
		y = get(y);
		int rtx = find(x);
		int rty = find(y);
		if(op[0] == 'o')
		{
			if(rtx == rty && ((d[y] - d[x]) % 2 + 2) % 2 == 0)
			{
				res = i - 1;
				break;
			}
			if(rtx != rty)
			{
				fa[rtx] = rty;
				d[rty] = d[y] - d[x] - 1;
			}
		}
		else
		{
			if(rtx == rty && ((d[y] - d[x]) % 2 + 2) % 2 == 1)
			{
				res = i - 1;
				break;
			}
			if(rtx != rty)
			{
				fa[rtx] = rty;
				d[rty] = d[y] - d[x];
			}
		}
	}
	cout << res << endl;
}