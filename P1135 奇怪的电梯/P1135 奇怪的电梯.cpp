#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int>> q;
bool vis[205];
int ans[205];
int jp[205];
int st;
int ed;
int n;

int main()
{
	cin>>n>>st>>ed;
	for(int i=1;i<=n;i++) cin>>jp[i];
	if(st == ed)
	{
		cout<<'0'<<endl;
		return 0;
	}
	if(st - jp[st] >= 1) 
	q.push(make_pair(st,-1));
	if(st + jp[st] <= n)
	q.push(make_pair(st,1));
	ans[st] = 0;
	vis[st] = true;
	while(!q.empty())
	{
		int hi = q.front().first;
		int next = q.front().second * jp[hi] + hi;
		if(next == ed) 
		{
			cout<<ans[hi]+1<<endl;
			return 0;
		}
		if(vis[next] == false && next >= 1 && next <= n)
		{
			vis[next] = true;
			ans[next] = ans[hi] + 1;
			if(next - jp[next] >= 1) q.push(make_pair(next,-1));
			if(next + jp[next] <= n) q.push(make_pair(next,1));
		}
		q.pop();
	}
	cout<<"-1"<<endl;
}