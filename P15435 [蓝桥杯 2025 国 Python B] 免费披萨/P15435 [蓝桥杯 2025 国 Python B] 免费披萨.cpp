#include<bits/stdc++.h>
#define int long long
using namespace std;
int gcd_(int a,int b)
{
	if(a < b) swap(a,b);
	if(a % b == 0) return b;
	return gcd_(b,a % b);
}
int a,Max = -1,ans = LLONG_MAX;
vector<int> vis;
void dfs(int pos,int num)
{
	if(pos == 9)
	{
		int d = gcd_(a,num);
		if(d > Max || (d == Max && num < ans)) 
		{
			ans = num;
			Max = d;
		}
		return;
	}
	for(int i = 1;i <= 8;i++)
	{
		if(vis[i] > 0)
		{
			vis[i]--;
			num = num * 10 + i;
			dfs(pos + 1,num);
			num /= 10;
			vis[i]++;
		}
	}
}

signed main()
{
	cin >> a;
	for(int i = 1;i <= 8;i++)
	{
		vis.clear();
		vis.resize(9,1);
		vis[i]++;
		dfs(0,0);
	}
	cout << ans << endl;
}
