#include<bits/stdc++.h>
using namespace std;

int l[1000005],r[1000005];
queue<int> q;

int main()
{
	int n;
	int depth=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
	}
	
	q.push(1);
	while(!q.empty())
	{
		depth++;
		int queueSize=q.size();//很有必要的记录  不记录会边入队边循环   就不是层级遍历了
		for(int i=0;i<queueSize;i++)
		{
			int node=q.front();
			q.pop();
			if(l[node]!=0) q.push(l[node]);
			if(r[node]!=0) q.push(r[node]);
		}
	}
	cout<<depth<<endl;
}