#include<bits/stdc++.h>
using namespace std;
int n,m;
char Flag[53][53];
int len=0;
int ans[20000];
int Cnt(int x,int y)
{
	int Count=0;
	for(int i=1;i<x;i++)
		for(int j=1;j<=m;j++)
		if(Flag[i][j]!='W') Count++;
		
	for(int i=x;i<=y;i++)
		for(int j=1;j<=m;j++)
		if(Flag[i][j]!='B') Count++;
		
	for(int i=y+1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if(Flag[i][j]!='R') Count++;	
		
	return Count;
}

int main()
{

	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>Flag[i][j];
	
	for(int i=2;i<=n-1;i++)
		for(int j=i;j<=n-1;j++)
			ans[++len]=Cnt(i,j);
			
	sort(ans+1,ans+1+len);
	
	cout<<ans[1]<<endl;		
}