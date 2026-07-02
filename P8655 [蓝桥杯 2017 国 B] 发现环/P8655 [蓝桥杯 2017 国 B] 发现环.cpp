#include<bits/stdc++.h>
using namespace std;
int n;
vector< vector<int> > tr(100005);
bool vis[200005];
int cnt[100005];
deque<int> num;
int flag = 0;

void Print(void)
{
	int pos;bool st = false;
	for(int i = 0;i < num.size();i++)
	{
		if(num[i] == flag) 
		{
			pos = i;
			break;
		}
	}
	sort(num.begin() + pos,num.end());
	for(int i = 0 + pos;i < num.size();i++) cout << num[i] << ' ';
	exit(0);
}

void dfs(int fa,int u)
{
	for(auto & v : tr[u])
	{
		if(fa == v || flag > 0) continue;
		if(vis[v])
		{
			flag = v;
			Print();
			return;
		}
		vis[v] = true;
		num.push_back(v);
		dfs(u,v);
		vis[v] = false;
		num.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int f;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int u,v;
		cin >> u >> v;
		tr[u].emplace_back(v);
		tr[v].emplace_back(u);
	}
	
	dfs(-1,1);

	if(flag == 0)
	{
		
		for(int i = 1;i <= n;i++)
		{
			memset(cnt,0,sizeof cnt);
			for(auto & v : tr[i])
			{
				cnt[v]++;
				if(cnt[v] == 2)
				{
					cout << min(i,v) << ' ' << max(i,v) << endl;
					return 0;
				}
			}
			
		}
	}
}