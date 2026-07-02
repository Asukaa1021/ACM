#include<bits/stdc++.h>
int cnt;
int count;
int n,k;
bool N[25];
int num[25];
bool pd(int x)
{
	if(x==2) return 1;//特例
	if(x==3) return 1;//特例
	if(x%2==0) return 0;
	if(x%3==0) return 0;
	for(int i=5;i*i<=x;i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}

void xs(int cho,int depth,int cnt)
{
	if(depth==k)
	{
		if(pd(cnt)) count++;
		return;
	}
	for(int i=cho;i<=n;i++)
	{
		if(!N[i])
		{
			N[i]=1;
			xs(i,depth+1,cnt+num[i]);//搜索下一个
			N[i]=0;//回溯
		}
	}
}

int main()
{

	memset(num,0,sizeof num);

	std::cin>>n>>k;

	for(int i=1;i<=n;i++) std::cin>>num[i];
	xs(1,0,0);
	std::cout<<count<<std::endl;
}