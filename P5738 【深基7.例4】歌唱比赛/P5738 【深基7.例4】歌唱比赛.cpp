#include<bits/stdc++.h>
using namespace std;

float p(float a[],int n)
{
	sort(a+1,a+n+1);
	float ans=0;
	for(int i=2;i<n;i++)
	{
		ans+=a[i];
	}
	return (ans/(n-2));
}
float a[25];
float b[105];
int main()
{
	int n,m;
	cin>>n>>m;
	
	int k=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[j];
		}
		b[++k]=p(a,m);
	}
	float M=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]>M) M=b[i];
	}
	printf("%.2f",M);
	return 0;
}