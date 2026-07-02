#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int sum=0;
	int a[100005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	} 
	int cnt=0;
	int len;
	int p=1;
	while(sum>0)
	{
		for(int i=p;i<=n;i++)
		{
			if(a[i]!=0)
			{
				p=i;//从p点开始寻找
				a[i]--;
				len=1;
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]!=0)
					{
						a[j]--;
						len++;
					}
					else
					{
						goto end_;
					}
				}
				goto end_;
			}
		}
		end_:;
		sum-=len;
		cnt++;
	}
	cout<<cnt<<endl;
}