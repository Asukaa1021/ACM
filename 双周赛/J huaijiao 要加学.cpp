#include<bits/stdc++.h>
using namespace std;

struct node
{
	double c;
	int w;
	double p;
}a[2005];

bool cmp(node a,node b)
{
	return a.p > b.p;
}

int main()
{
	int n , m;
	double ans = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i].c;
	for(int i = 1;i <= n;i++) cin >> a[i].w;
	for(int i = 1;i <= n;i++)
	{
		a[i].p = a[i].c/(double)a[i].w;
	}
	sort(a + 1,a + 1 + n,cmp);
	
	for(int i = 1;i <= n;i++)
	{
		if(a[i].w <= m)
		{
			ans += a[i].c * 100;
			m -= a[i].w;
		}
		else
		
		{
			ans += a[i].c * 100 * (double)m / (double)a[i].w;
			break;
		 } 
	}
	printf("%.4lf",ans);
}