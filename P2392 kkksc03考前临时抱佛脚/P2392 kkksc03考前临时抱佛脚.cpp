#include<bits/stdc++.h>
using namespace std;

int num1,num2,num3,num4;

int Time[25];

void Cin(int num)
{
	Time[0]=0;
	for(int i=1;i<=num;i++)
	{
		cin>>Time[i];
		Time[0]+=Time[i];
	 } 
	sort(Time+1,Time+1+num);
}

int Solve(int x[],int num)
{
	if(num==1) return x[1];
	else{
	int Flag=x[0]/2;
	int dp[25][605];
	memset(dp,0,sizeof dp);
	for(int i=1;i<=num;i++)
	{
		for(int j=1;j<=Flag;j++)
		{
			if(Time[i]>j) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(Time[i]+dp[i-1][j-Time[i]],dp[i-1][j]);
		}
	}
	
	return Time[0]-dp[num][Flag];
	}
	
}

int main()
{
	int ans=0;
	cin>>num1>>num2>>num3>>num4;
	Cin(num1);
	ans+=Solve(Time,num1);
	Cin(num2);
	ans+=Solve(Time,num2);
	Cin(num3);
	ans+=Solve(Time,num3);
	Cin(num4);
	ans+=Solve(Time,num4);
	cout<<ans<<endl;
}