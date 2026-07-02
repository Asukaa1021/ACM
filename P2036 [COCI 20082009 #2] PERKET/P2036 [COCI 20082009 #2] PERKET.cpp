#include<bits/stdc++.h>
using namespace std;
int n,s[15],b[15];
int ans=INT_MAX;
bool chosed[25];
int S=1,B=0;
void bfs(int x,int depth)
{
	if(depth==x)
	{	ans=min(ans,abs(S-B));
		return ;
	 } 
	for(int u=1;u<=n;u++)
	{
		if(chosed[u]) continue;
		chosed[u]=1;
		S*=s[u];
		B+=b[u];
		bfs(x,depth+1);
		S/=s[u];
		B-=b[u];
		chosed[u]=0;
	}
}


int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i]>>b[i];
		
	for(int i=1;i<=n;i++)
	{
		bfs(i,0);
		S=1,B=0;
	}
	
	
	cout<<ans<<endl;
	
	
}