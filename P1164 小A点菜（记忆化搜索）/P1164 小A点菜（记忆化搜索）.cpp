#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[105],meno[105][1000005];

int dfs(int pos,int sum)//此时判断选不选pos，且选之前总和为sum
{
	if(sum==m) return 1;//选之前若为m  return 1
	if(pos>n) return 0;
	if(sum>m) return 0;
	
	if(meno[pos][sum]!=-1) return meno[pos][sum];
	
	int choose=dfs(pos+1,sum+a[pos]);
	int skip=dfs(pos+1,sum);
	
	return meno[pos][sum]=skip+choose;
}

int main()
{
	cin>>n>>m;
	memset(meno,-1,sizeof meno);
	for(int i=1;i<=n;i++) cin>>a[i];
	ans=dfs(1,0);
	cout<<ans;
	
}