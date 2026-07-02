#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,mid;
int ans = INT_MAX;
int melon[35];

unordered_map<int,int> mp;

void dfs(int sum,int pos,int cnt)
{
	if(sum > m || pos > mid) return;
	if(sum == m)
	{
		ans = min(ans,cnt);
		return;
	}
	if(mp.count(sum) && mp[sum] < cnt) return;
	mp[sum] = cnt;
	dfs(sum,pos + 1,cnt);
	dfs(sum + melon[pos + 1] * 2,pos + 1,cnt);
	dfs(sum + melon[pos + 1],pos + 1,cnt + 1);
}

void DFS(int sum,int pos,int cnt)
{
	if(sum > m || pos > n) return;
	if(sum == m)
	{
		ans = min(ans,cnt);
		return;
	}
	if(mp.count(m - sum))
	{
		ans = min(ans,cnt + mp[m - sum]);
		return;
	}
	
	DFS(sum,pos + 1,cnt);
	DFS(sum + melon[pos + 1] * 2,pos + 1,cnt);
	DFS(sum + melon[pos + 1],pos + 1,cnt + 1);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	m *= 2;
	for(int i = 1;i <= n;i++) cin >> melon[i];
	mid = n / 2;
	sort(melon + 1,melon + 1 + n);
	dfs(0,0,0);
	DFS(0,mid,0);
	
	cout << ((ans == INT_MAX) ? -1 : ans) << endl;
}