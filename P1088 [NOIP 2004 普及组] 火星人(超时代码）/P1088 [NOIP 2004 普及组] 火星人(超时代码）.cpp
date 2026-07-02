#include<bits/stdc++.h>//超时代码
using namespace std;
int n,number;
int flag=INT_MAX;
int a[10005];
int Sort[10005];
bool choice[10005];
int Count=0;
void dfs1(int depth)
{
	if(depth==n)
	{
		Count++;
		bool pd=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=Sort[i]) pd=0;
		}
		if(pd==1)
		{
			flag=Count+number;
		}
		if(flag==Count)
		{
			for(int i=1;i<=n;i++)
			{
				cout<<Sort[i]<<" ";
			}
			exit(0);
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!choice[i])
		{
			choice[i]=1;
			Sort[depth+1]=i;
			dfs1(depth+1);
			choice[i]=0;
		}
	}
}

int main()
{
	cin>>n>>number;
	for(int i=1;i<=n;i++)	cin>>a[i];
	dfs1(0);
}