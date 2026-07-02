#include<bits/stdc++.h>
using namespace std;
long long a[1000005],b[100005];
int main()
{
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	
	for(int i=1;i<=m;i++)
	{
		long long l=1,r=n,ans=-1;
		while(l<=r)
		{	
		
			long long mid=(l+r)/2;
			if(a[mid]==b[i])
			{
				ans=mid;
				r=mid-1;
			}
			else if(a[mid]<b[i])
			{
				l=mid+1;
			}
			else 
			{
				r=mid-1;
			}
			
		}
		cout<<ans<<" ";
	}
}