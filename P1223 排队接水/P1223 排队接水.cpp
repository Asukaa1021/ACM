#include<bits/stdc++.h>
using namespace std;

struct p
{
	double t;
	int num;	
}a[1005];

bool cmp(p a,p b)
{
	if(a.t!=b.t)
	return a.t < b.t;
	return a.num < b.num;
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].t;
		a[i].num=i;
	} 
	sort(a+1,a+1+n,cmp);
	double sum=0;
	for(int i=1;i<=n;i++)
	{
		cout<<a[i].num<<" ";
		sum+=a[i].t*(n-i);
	}
	printf("\n%.2lf",sum/n);
}