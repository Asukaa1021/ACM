#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m;
	cin >> n >> m;
	bool flg1 = false,flg2 = false,flg3 = false;
	vector< vector<int>> a(1001,vector<int> (101));
	vector< vector<bool>> vis(1001,vector<bool> (101));
	for(int i = 0;i < m;i++)
	{
		int In,Out,ans = 0;
		flg2 = false,flg3 = false;
		cin >> In;
		for(int j = 1;j <= In;j++)
		{
			int idx,num;
			cin >> idx >> num;
			if(idx == -1 && num == -1)
			{
				flg2 = true;
			}
			else if(!vis[idx][num] && idx < i)
			{
				ans += a[idx][num];
				vis[idx][num] = true;
			}
			else flg3 = true;
		}
		if(flg3) flg1 = true;
		cin >> Out;
		for(int j = 0;j < Out;j++)
		{
			int idx,sum;
			cin >> idx >> sum;
			ans -= sum;
			a[i][j] = sum;
		}
		if(flg2) continue;
		if(ans != 0) flg1 = true;
	}
	if(flg1) cout << "NO" << endl;
	else cout << "YES" << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}