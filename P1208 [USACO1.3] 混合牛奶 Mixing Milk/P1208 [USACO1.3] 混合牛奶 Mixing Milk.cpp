#include<bits/stdc++.h>
using namespace std;

struct farmer
{
	int val;
	int m;
}a[2000005];

bool cmp(farmer a,farmer b)
{
	return a.val<b.val;
}

int main()
{
	int M,n;
	cin>>M>>n;
	for(int i=1;i<=n;i++) cin>>a[i].val>>a[i].m;
	sort(a+1,a+1+n,cmp);
	int i=1;
	long long ans=0;
	while(M>0)
	{
		if(M>a[i].m) 
		{
			ans+=a[i].m*a[i].val;
			M-=a[i].m;
			i++;
		}
		else
		{
			ans+=M*a[i].val;
			break;
		}
	}
	cout<<ans<<endl;
}