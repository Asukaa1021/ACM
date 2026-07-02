#include<bits/stdc++.h>
using namespace std;
int M;
int des_time[305][305];
bool vis[305][305];
int ans[305][305];
int dx[5]={1,-1,0,0,0};
int dy[5]={0,0,1,-1,0};
queue<pair<int,int>> q;
int main()
{
	memset(des_time,-1,sizeof des_time);
	scanf("%d",&M);
	for(int i=1;i<=M;i++)
	{
		int X,Y,T;
		cin>>X>>Y>>T;
		for(int j=0;j<=4;j++)
		{
			int x = X + dx[j];
			int y = Y + dy[j];
			if(x >= 0 && y >= 0 && (des_time[x][y] == -1 || T < des_time[x][y]))	des_time[x][y] = T;//在T时刻被烧焦 
		}//要在destime等于-1或者大于T时更新！！！
	}
	if(des_time[0][0] == -1)
	{
		cout<<"0"<<endl;
		return 0;
	} 
	q.push(make_pair(0,0));
	vis[0][0] = true;
	while(!q.empty())
	{
		int fx = q.front().first;
		int fy = q.front().second;//记录上一步x,y;
		for(int i = 0;i <= 3;i++)
		{
			int x = fx + dx[i];
			int y = fy + dy[i];//走的地方
			if(x >= 0 && y >= 0 && vis[x][y] == false)//x,y 合法
			{
				if(des_time[x][y] == -1)//safe
				{
					cout<<ans[fx][fy]+1<<endl;
					return 0;
				}
				if(des_time[x][y] > ans[fx][fy] + 1)
				{
					ans[x][y] = ans[fx][fy] + 1;
					vis[x][y] = true;
					q.push(make_pair(x,y));
				}
			}
		}
		q.pop();
	}
	cout<<"-1"<<endl;
}