#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000005];

bool check(int h)
{
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		if(h<a[i]) 
		{
			sum+=a[i]-h;
		}
	}
	if(sum>=m) return true;
	else return false;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	int l=0,r=400000;
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
			
		}
		else r=mid-1;
	}
	cout<<ans<<endl;
}