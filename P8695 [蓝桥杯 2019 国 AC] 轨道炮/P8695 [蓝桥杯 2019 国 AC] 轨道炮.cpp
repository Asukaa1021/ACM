#include<bits/stdc++.h>
using namespace std;
const int N = 1000000;
int n;
struct node
{
	int x,y;
	char to;
	int v;
};
vector<int> cntx(2000005),cnty(2000005);
vector<node> enemy(1005);
int ans = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int x,y;
		cin >> enemy[i].x >> enemy[i].y >> enemy[i].v >> enemy[i].to;
		enemy[i].x += N;
		enemy[i].y += N;
		cntx[enemy[i].x]++;
		cnty[enemy[i].y]++;
		ans = max(ans,max(cnty[enemy[i].y],cntx[enemy[i].x]));
	}
	int num = n;
	vector<bool> vis(1005);
	int cnt = 0;
	while(num > ans && ++cnt <= 2000000)
	{
		for(int i = 1;i <= n;i++)
		{
			if(vis[i]) continue;
			if(enemy[i].to == 'U')
			{
				cnty[enemy[i].y]--;
				enemy[i].y += enemy[i].v;
				if(enemy[i].x < 0 || enemy[i].x > N * 2 || enemy[i].y < 0 || enemy[i].y > N * 2 )
				{
					vis[i] = true;
					num--;
					continue;
				}
				cnty[enemy[i].y]++;
			}	
			if(enemy[i].to == 'D')
			{
				cnty[enemy[i].y]--;
				enemy[i].y -= enemy[i].v;
				if(enemy[i].x < 0 || enemy[i].x > N * 2 || enemy[i].y < 0 || enemy[i].y > N * 2 )
				{
					vis[i] = true;
					num--;
					continue;
				}
				cnty[enemy[i].y]++;
			}	
			if(enemy[i].to == 'L')
			{
				cntx[enemy[i].x]--;
				enemy[i].x -= enemy[i].v;
				if(enemy[i].x < 0 || enemy[i].x > N * 2 || enemy[i].y < 0 || enemy[i].y > N * 2 )
				{
					vis[i] = true;
					num--;
					continue;
				}
				cntx[enemy[i].x]++;
			}	
			if(enemy[i].to == 'R')
			{
				cntx[enemy[i].x]--;
				enemy[i].x += enemy[i].v;
				if(enemy[i].x < 0 || enemy[i].x > N * 2 || enemy[i].y < 0 || enemy[i].y > N * 2 )
				{
					vis[i] = true;
					num--;
					continue;
				}
				cntx[enemy[i].x]++;
			}
		}
		bool flag = false;
		for(int i = 1;i <= n;i++)
		{
			if(vis[i]) continue;
			if(enemy[i].v != 0) flag = true;
			ans = max(ans,max(cntx[enemy[i].x],cnty[enemy[i].y]));
		}
		if(!flag) break;
	}
	cout << ans << endl;
}