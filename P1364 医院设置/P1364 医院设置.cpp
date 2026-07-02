#include<bits/stdc++.h>
using namespace std;

vector< vector<long long> > edge;
vector<long long> root;
int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	edge.resize(n + 1,vector<long long> (n + 1,INT_MAX));
	root.resize(n + 1);
	for(int i = 1;i <= n;i++)
	{
		long long num;
		long long l,r;
		cin >> num >> l >> r;
		root[i] = num;
		edge[i][i] = 0;
		edge[i][l] = 1;
		edge[i][r] = 1;
		edge[r][i] = 1;
		edge[l][i] = 1;
	}
	for(int k = 1;k <= n;k++)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(edge[i][j] > edge[i][k] + edge[k][j])
				{
					edge[i][j] = edge[i][k] + edge[k][j];
				}
			}
		}
	}
	long long ans = INT_MAX;
	for(int i = 1;i <= n;i++)
	{
		long long sum = 0;
		for(int j = 1;j <= n;j++)
		{
			sum += edge[i][j] * root[j];
		}
		ans = min(ans,sum);
	}
	cout << ans << endl;
}