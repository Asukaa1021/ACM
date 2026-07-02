#include<bits/stdc++.h>
using namespace std;

int n,m;
double a[405];
double b[405][405];
bool c[405];

struct node
{
	double p;
	int x;
}reason[405];
double dp[405];

bool cmp(node a,node b)
{
	if(fabs(a.p - b.p) < 1e-6) return a.x < b.x;
	else return a.p > b.p;
}

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		a[i] *= 0.01;
	 } 
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cin >> b[i][j];
			b[i][j] *= 0.01;
		}
	}
	int k;
	cin >> k;
	for(int i = 1;i <= k;i++)
	{
		int num;
		cin >> num;
		c[num] = true;
	}
	double sum = 0;
	for(int i = 1;i <= n;i++)
	{
		dp[i] = a[i];
		for(int j = 1;j <= m;j++)
		{
			if(c[j]) dp[i] *= b[i][j];
			else dp[i] *= (1 - b[i][j]);
		}
		sum += dp[i];
	}
	for(int i = 1;i <= n;i++)
	{
		reason[i].x = i;
		reason[i].p = dp[i] / sum * 100;
	}
	sort(reason + 1,reason + 1 + n,cmp);
	for(int i = 1;i <= n;i++)
	{
		printf("%d %.2lf\n",reason[i].x,reason[i].p);
	}
}