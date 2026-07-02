#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e4 + 20;
long long n,m;
struct node
{
	long long x,y,r;
}arr[N];
bool vis[N];
queue<pair<pair<long long,long long>,long long>> q;
bool cmp(node a,node b)
{
	if(a.x != b.x) return a.x < b.x;
	else return a.y < b.y;
}

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)	cin >> arr[i].x >> arr[i].y >> arr[i].r;	
	sort(arr + 1,arr + 1 + n,cmp);
	vector<long long> X(n + 1);
	vector<long long> Y(n + 1);
	vector<long long> R(n + 1);
	for(int i = 1;i <= n;i++)
	{
		X[i] = arr[i].x;
		Y[i] = arr[i].y;
		R[i] = arr[i].r;
	}
	long long ans = 0;
	
	for(int i = 1;i <= m;i++)
	{
		long long x,y,r;
		cin >> x >> y >> r;
		q.push({{x,y},r});
	}
	while(!q.empty())
	{
		long long x = q.front().first.first;
		long long y = q.front().first.second;
		long long rr = q.front().second;
		q.pop();
		int r = lower_bound(X.begin(),X.end(),x + rr + 1) - X.begin();
		int l = lower_bound(X.begin(),X.end(),x - rr) - X.begin();
		if(l < 1) l = 1;
		if(r > n) r = n;
		for(int i = l;i <= r;i++)
		{
			if(vis[i]) continue;
			long long d = (X[i] - x) * (X[i] - x) + (Y[i] - y) * (Y[i] - y);
			if(d <= rr * rr)//能引爆
			{
				vis[i] = true;
				ans++;
				q.push({{X[i],Y[i]},R[i]});
			}
		}
	}
	cout << ans << endl;
}