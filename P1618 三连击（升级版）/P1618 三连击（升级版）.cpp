#include<bits/stdc++.h>

int num[10];

int main()
{
	int A,B,C;	
	std::cin>>A>>B>>C;
	int count=0;
	for(int i=1;i<=999;i++)
	{
		int a,b,c;
		a=A*i;
		b=B*i;
		c=C*i;
		if(100<=a&&a<=999&&100<=b&&b<=999&&100<=c&&c<=999)
		{
			for(int j=1;j<=3;j++)
			{
				num[a%10]++;
				a/=10;
			}
			for(int j=1;j<=3;j++)
			{
				num[b%10]++;
				b/=10;
			}
			for(int j=1;j<=3;j++)
			{
				num[c%10]++;
				c/=10;
			}
			for(int i=1;i<=9;i++) if(num[i]!=1) goto P;
			count++;
			std::cout<<A*i<<" "<<B*i<<" "<<C*i<<std::endl;
		}
		P:
		memset(num,0,sizeof num);
	}	
	if(count==0) std::cout<<"No!!!"<<std::endl;
}