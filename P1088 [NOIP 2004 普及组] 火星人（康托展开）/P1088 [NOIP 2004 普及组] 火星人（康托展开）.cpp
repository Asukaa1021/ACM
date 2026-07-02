#include<bits/stdc++.h>
using namespace std;
int n,Plus,num=0;
bool used[10005];
bool chosed[10005];
int a[10005];
int kt[10005];
int main()
{
	cin>>n>>Plus;
	int num=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int k=a[i];
		for(int j=1;j<=a[i];j++)
		{
			k-=used[j];
		}
		used[a[i]]=1;
		kt[i]=k-1;
	}	//康托展开
	kt[n]+=Plus;
	for(int i=n;i>=1;i--)
	{
		kt[i-1]+=kt[i]/(n-i+1);
		kt[i]%=(n-i+1);
	}//更新数字，处理进位
	memset(chosed,1,sizeof chosed);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{	
			if(kt[i]==0 && chosed[j]==1)
			{
				cout<<j<<" ";
				chosed[j]=0;
				break;
			}
			if(chosed[j]==1)
			{
				kt[i]--;
			}
		}
	}//复原输出
	
}