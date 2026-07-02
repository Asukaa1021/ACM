#include<bits/stdc++.h>
using namespace std;

struct goods
{
	double h,v;	
}a[105];

bool cmp(goods a,goods b)
{
	return a.v/a.h>b.v/b.h;
}

int main()
{
	double ans=0;
	int n;
	double T;
	cin>>n>>T;
	for(int i=1;i<=n;i++) cin>>a[i].h>>a[i].v;
	
	sort(a+1,a+1+n,cmp);
	
	for(int i=1;i<=n;i++)
	{
		if(T>a[i].h)
		{
			T-=a[i].h;
			ans+=a[i].v;
		}
		else
		{
			ans+=a[i].v/a[i].h*T;
			break;
		}
	}
	printf("%.2lf",ans);
}