#include<bits/stdc++.h>
using namespace std;
int n;
string s[25];
int vis[25];
int ans=0;
void dfs(const string p)
{
	int len = p.size();
	ans = max(ans,len);
	for(int i=1;i<=n;i++)
	{
		if(vis[i]>=2) continue;
		for(int j=1;j<min(p.size(),s[i].size());j++)
		{
			if(s[i].substr(0,j) == p.substr(p.size()-j))
			{
				vis[i]++;
				dfs(p+s[i].substr(j));
				vis[i]--;
			}
		}
	}
}


int main()
{
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>s[i];
	char c;
	cin>>c;
	for(int i = 1;i <= n;i++)
	{
		if(s[i][0] == c)
		{
			vis[i]++;
			dfs(s[i]);
			vis[i]--;
		}
	}
	cout<<ans<<endl;
}