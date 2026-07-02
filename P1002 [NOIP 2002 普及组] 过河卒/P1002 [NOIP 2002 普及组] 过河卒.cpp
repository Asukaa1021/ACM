#include<bits/stdc++.h>
using namespace std;

long long table[25][25];

int main()
{
	int xb,yb,xm,ym;
	cin>>xb>>yb>>xm>>ym;
	table[xm][ym]=-1;
	if(xm-1>=0)
	table[xm-1][ym+2]=-1;
	table[xm+1][ym+2]=-1;
	if(xm-1>=0&&ym-2>=0)
	table[xm-1][ym-2]=-1;
	if(ym-2>=0)
	table[xm+1][ym-2]=-1;
	if(xm-2>=0)
	table[xm-2][ym+1]=-1;
	if(ym-1>=0)
	table[xm+2][ym-1]=-1;
	if(xm-2>=0&&ym-1>=0)
	table[xm-2][ym-1]=-1;
	table[xm+2][ym+1]=-1;
	
	for(int i=0;i<=xb;i++)
	{
		if(table[i][0]>=0)
		 table[i][0]=1;
		 else break;//如果边缘有马能走过的点  后面的点都为0
	 }
	for(int i=0;i<=yb;i++)
	{
		if(table[0][i]>=0)
		 table[0][i]=1;
		 else break;
	 } 


	for(int i=1;i<=xb;i++)
		for(int j=1;j<=yb;j++)
		{
			if(table[i][j]>=0)
			{
				if(table[i][j-1]>0)
				table[i][j]+=table[i][j-1];
				if(table[i-1][j]>0)
				table[i][j]+=table[i-1][j];
			}
		}
		
	cout<<table[xb][yb]<<endl;	
}