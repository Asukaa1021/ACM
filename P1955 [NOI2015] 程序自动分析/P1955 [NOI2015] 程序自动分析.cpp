#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
int len;
vector<int> a,b,e,fa,rank_;
int get(int x)
{
	if(mp.count(x) == 0) mp[x] = ++len;
	return mp[x];
}

int find(int x)
{
	if(fa[x] == x) return x;
	else return find(fa[x]);
}

void unite(int x,int y)
{
	int rootx = find(x);
	int rooty = find(y);
	if(rootx == rooty) return;
	if(rank_[x] == rank_[y])
	{
		fa[y] = x;
		rank_[x]++;
	}
	else if(rank_[x] > rank_[y])
	{
		fa[y] = x;
	}
	else
	{
		fa[x] = y;
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
    	int n;
    	cin >> n;
    	mp.clear();
    	len = 0;
    	a.clear();
    	b.clear();
    	e.clear();
		fa.clear();
		rank_.clear();
		rank_.resize(2 * n + 2);
    	a.resize(n + 1);
    	b.resize(n + 1);
    	e.resize(n + 1);
    	fa.resize(2 * n + 2);
    	for(int i = 1;i <= 2 * n;i++) fa[i] = i;
    	for(int i = 1;i <= n;i++)
    	{
    		cin >> a[i] >> b[i] >> e[i];
    		a[i] = get(a[i]);
    		b[i] = get(b[i]);
		}
		for(int i = 1;i <= n;i++)
		{
			if(e[i] == 0) continue;
			unite(a[i],b[i]);
		}
		bool flag = true;
		for(int i = 1;i <= n;i++)
		{
			if(e[i] == 0)
			{
				int x = find(a[i]),y = find(b[i]);
				if(x == y) flag = false;
			}
		}
		flag ? puts("YES") : puts("NO");
	}
    return 0;
}