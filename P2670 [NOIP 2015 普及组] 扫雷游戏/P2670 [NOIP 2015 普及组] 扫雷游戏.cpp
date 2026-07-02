#include<bits/stdc++.h>
using namespace std;

char a[105][105];
int b[105][105];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='*') continue;
			int num=0;
			if(a[i][j+1]=='*') num++;
			if(a[i][j-1]=='*')num++;
			if(a[i+1][j]=='*')num++;
			if(a[i-1][j]=='*')num++;
			if(a[i+1][j+1]=='*')num++;
			if(a[i+1][j-1]=='*')num++;
			if(a[i-1][j+1]=='*')num++;
			if(a[i-1][j-1]=='*')num++;
			b[i][j]=num;
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!='*')
			cout<<b[i][j];
			else cout<<'*';
		}
		cout<<endl;
	}
			
	return 0;
}
