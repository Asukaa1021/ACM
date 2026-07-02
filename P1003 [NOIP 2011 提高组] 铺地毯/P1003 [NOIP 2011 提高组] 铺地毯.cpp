#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
	cin >> n;
	vector<vector<int>> g(n + 5,vector<int> (5));
	for(int i = 1;i <= n;i++)
	{
		cin >> g[i][1] >> g[i][2] >> g[i][3] >> g[i][4];
	 } 
	int x,y;
	cin >> x >> y;
	for(int i = n;i >= 1;i--)
	{
		if(g[i][1] <= x && x <= g[i][1] + g[i][3] && g[i][2] <= y && y <= g[i][2] + g[i][4]) 
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}