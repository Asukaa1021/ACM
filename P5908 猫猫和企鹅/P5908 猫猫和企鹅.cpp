#include<bits/stdc++.h>
using namespace std;
int n,d,ans,x,y;

vector<int> a[100005];

struct node{
	int x,s=0;
}p;

void bfs(void)
{
	queue<node> q;
	q.push({1,0});
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		if(p.s>=d) continue;//大于路径  排除
		for(int i=0;i<a[p.x].size();i++)
		{
			q.push({a[p.x][i],p.s+1});
			ans++;
		}
	}
}

int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		a[min(x,y)].push_back(max(x,y));//将大的放在小的里面
	}
	bfs();
	printf("%d",ans);
}