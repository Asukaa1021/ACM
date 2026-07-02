#include<bits/stdc++.h>
using namespace std;
int n;
double p;
double a[100005],b[100005];

bool check(double x)
{
	double sum = 0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]/a[i] < x)
		{
			sum += (x - b[i] / a[i]) * a[i] / p;
		}
	}
	return sum <= x;
}

int main()
{
	cin>>n>>p;
	double aSum = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		aSum+=a[i];
	}
	if(aSum <= p)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	double ans;
	double l=0,r=10000000000;
	while(l <= r)
	{
		double mid = l + (r - l) / 2;
		if(check(mid))
		{
			ans = mid;
			l = mid + 0.00001;
		}
		else r = mid - 0.00001;
	}
	printf("%.10lf",ans);
}