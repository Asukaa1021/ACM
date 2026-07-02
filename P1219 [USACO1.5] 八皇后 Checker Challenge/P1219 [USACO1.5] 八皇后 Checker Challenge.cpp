#include<bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;
int y[15];
int vis[15][2];

bool check(int x1,int y1)
{
	for(int i=1;i<y1;i++)
		if((vis[i][1] - vis[i][0] == y1 - x1 || vis[i][1] + vis[i][0] == x1 + y1)) return false;
	return true;
}

void Print()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(y[j] == i) cout<<j<<" ";
		}
	}
	cout<<endl;
}

void dfs(int y1)
{
	if(y1 == n+1) 
	{
		cnt++;
		if(cnt <= 3) Print();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(y[i] == 0 && check(i,y1))
		{
			y[i] = y1;
			vis[y1][0]=i;
			vis[y1][1]=y1;
			dfs(y1+1);
			vis[y1][0]=0;
			vis[y1][1]=0;
			y[i] = 0;
		}
	}
	
}

int main()
{
	cin>>n;
	dfs(1);
	cout<<cnt<<endl;
}