#include<bits/stdc++.h>
using namespace std;

int a[505][505];


void F(int x,int y,int r,int z)
{
	int first[505][505];
	for(int i=x-r;i<=x+r;i++)
		for(int j=y-r;j<=y+r;j++)
		first[i][j]=a[i][j];
	if(z==0)	
	for(int i=x-r;i<=x+r;i++)
		for(int j=y-r;j<=y+r;j++)
		{
			a[i][j]=first[x+y-j][y+i-x];
		}
		
	else
	for(int i=x-r;i<=x+r;i++)
		for(int j=y-r;j<=y+r;j++)
		{
			a[i][j]=first[x+j-y][y+x-i];
		}		
}

int main()
{
	int n,m;
	int k=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=++k;
		}
	}
	while(m--)
	{
		int x,y,r,z;
		cin>>x>>y>>r>>z;
		F(x,y,r,z);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
