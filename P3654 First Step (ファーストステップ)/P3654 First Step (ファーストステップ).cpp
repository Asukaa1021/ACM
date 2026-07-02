#include<bits/stdc++.h>
using namespace std;

char Gym[104][104];
int r,c,k;

int pd(int x,int y)
{	
	int Cnt=2;
	if(k==1)//注意一人情况
	{
		if(Gym[x][y]=='#') Cnt=0;
		else Cnt=1;
	}
	
	else{
		
	int x2=x+k-1;
	int y2=y+k-1;
	for(int i=x;i<=x2;i++) 
	{
		if(Gym[i][y]=='#'||x2>r)
		{
			Cnt--;
			break;
		}
	}
	for(int j=y;j<=y2;j++) 
	{
		if(Gym[x][j]=='#'||y2>c)
		{
			Cnt--;
			break;
		}
	}
	}
	
	return Cnt;
}

int main()
{
	int ans=0;
	cin>>r>>c>>k;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			cin>>Gym[i][j];
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			ans+=pd(i,j);
			
	cout<<ans<<endl;				
			
}