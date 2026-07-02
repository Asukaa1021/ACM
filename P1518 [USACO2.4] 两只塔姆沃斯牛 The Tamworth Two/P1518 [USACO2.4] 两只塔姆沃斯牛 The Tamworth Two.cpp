#include<bits/stdc++.h>
using namespace std;

char Map[12][12];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int cow=0;
int man=0;
int cowx,cowy;
int manx,many;
int num=0;

void Go(int &a,int &b,int &k)
{
	
	if(Map[a+dx[k]][b+dy[k]]=='*') 
	{
		k++;
		k%=4;
	}
	else
	{
		a+=dx[k];
		b+=dy[k];
	}
}


int main()
{
	for(int i=0;i<=11;i++)
	{
		Map[i][0]='*';
		Map[0][i]='*';
		Map[11][i]='*';
		Map[i][11]='*';
	}

	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++)
			{
				cin>>Map[i][j];
				if(Map[i][j]=='C')
				{
					cowx=i;
					cowy=j;
					Map[i][j]='.';
				} 
				if(Map[i][j]=='F')
				{
					manx=i;
					many=j;
					Map[i][j]='.';
				}
			}
			
	int cx=cowx;
	int cy=cowy;
	int mx=manx;
	int my=many;		
	while(cowx!=manx||cowy!=many)
	{
		Go(cowx,cowy,cow);
		Go(manx,many,man);
		if(/*cx==cowx&&cy==cowy&&mx==manx&&my==many&&cow==0&&man==0*/num>=100000)//难绷
		{
			cout<<"0"<<endl;
			return 0;
		}
		num++;
	}
	cout<<num<<endl;
		
	return 0;
}