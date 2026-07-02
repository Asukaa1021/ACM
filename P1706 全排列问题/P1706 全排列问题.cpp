#include<bits/stdc++.h>
int n;
bool choice[15];
int Sort[15];

void dfs(int depth)
{
	if(depth==n)
	{
		for(int i=0;i<=n-1;i++) std::cout<<std::setw(5)<<Sort[i];
		std::cout<<std::endl;
	}
	for(int i=1;i<=n;i++)
	{
		if(!choice[i])//如果没被选
		{
			choice[i]=1;
			Sort[depth]=i;
			dfs(depth+1);
			choice[i]=0;
		}
	}
}

int main()
{
	
	std::cin>>n;
	dfs(0);
}