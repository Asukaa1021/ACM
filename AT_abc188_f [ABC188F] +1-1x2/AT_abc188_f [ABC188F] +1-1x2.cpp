#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b;
unordered_map<int,int> cache;

int dfs(int a,int b)
{
	if(a == b) return 0;
	if(a > b) return a - b;
	if(cache.count(b) != 0) return cache[b];
	cache[b] = b - a;
	if(b % 2 == 0)
	{
		cache[b] = min(cache[b],dfs(a,b / 2) + 1);
	}
	else 
	{
		cache[b] = min(cache[b],min(dfs(a,(b + 1) / 2) + 2,dfs(a,(b - 1) / 2) + 2));
	}
	return cache[b];
}

signed main()
{
	cin >> a >> b;
	cout << dfs(a,b) << endl;
}
