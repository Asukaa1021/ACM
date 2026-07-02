#include<bits/stdc++.h>
int n,k;
bool choice[22];
int num[22];
void dfs(int start,int depth)
{
	if(depth==k)
	{
		for(int i=1;i<=n;i++) 
		{
			if(choice[i]) std::cout<<std::setw(3)<<num[i];
		
		}	std::cout<<std::endl;
		return;
	}
	for(int i=start;i<=n;i++)
	{
		if(!choice[i]) 
		{
			choice[i]=1;
			dfs(i,depth+1);
			choice[i]=0;
		}
	}
}

int main()
{

	std::cin>>n>>k;
	for(int i=1;i<=n;i++) num[i]=i;
	dfs(1,0);
}