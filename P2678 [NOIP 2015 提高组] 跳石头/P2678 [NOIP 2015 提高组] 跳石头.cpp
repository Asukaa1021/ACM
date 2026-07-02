#include<bits/stdc++.h>
using namespace std;
int L,n,m;

int dis[50005];

bool check(int p)
{
	int tot=0;
	int i=0;
	int now=0;
	while(i<n+1)
	{	
		i++;
		if(dis[i]-dis[now]<p)
		{
			tot++;
		}
		else
		{
			now=i;
		}
	}
	if(tot>m) return false;
	else return true;
}

int main()
{
	cin>>L>>n>>m;
	for(int i=1;i<=n;i++) cin>>dis[i];
	dis[0]=0;
	dis[n+1]=L;
	int l=1,r=L;
	int ans=0;
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else 
		{
		r=mid-1;
		}
	}
	cout<<ans<<endl;
}