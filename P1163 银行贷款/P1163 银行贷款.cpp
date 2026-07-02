#include<bits/stdc++.h>
using namespace std;

double w0,w,m;
double k;

bool check(double x)
{
	double left = w0;
	for(int i=1;i<=m;i++)
	{
		left *= (x+1);
		left -= w;
	}
	return left <= 0;
}

int main()
{
	cin>>w0>>w>>m;
	double l=0,r=3;
	double ans;
	while(l<=r)
	{
		double mid = l + (r - l) / 2;
		if(check(mid))
		{
			ans = mid;
			l = mid + 0.00001;
		}
		else r = mid - 0.00001;
	}
	ans*=100;
	printf("%.1lf",ans);
}