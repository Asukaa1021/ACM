#include<bits/stdc++.h>
using namespace std;

int w,n,a[30005];
int main()
{
	cin>>w>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	int i=1,j=n;
	sort(a+1,a+1+n);
	while(i<=j)
	{
		if(i==j)
		{
			ans++;
			break;
		}
		if(a[i]+a[j]<=w)
		{
			ans++;
			i++;
			j--;
			continue;
		}
		else
		{
			ans++;
			j--;
			continue;
		}
	}
	cout<<ans<<endl;
}