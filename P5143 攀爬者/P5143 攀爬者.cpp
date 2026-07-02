#include<bits/stdc++.h>
using namespace std;

struct dot{
	double x,y,z;
}a[50005];

bool cmp(dot a,dot b)
{
	return a.z<b.z;
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a+1,a+1+n,cmp);
	double s=0;
	for(int i=1;i<n;i++)
	{
		s+=sqrt((a[i].x-a[i+1].x)*(a[i].x-a[i+1].x)+(a[i].y-a[i+1].y)*(a[i].y-a[i+1].y)+(a[i].z-a[i+1].z)*(a[i].z-a[i+1].z));
	}
	printf("%.3f",s);
}