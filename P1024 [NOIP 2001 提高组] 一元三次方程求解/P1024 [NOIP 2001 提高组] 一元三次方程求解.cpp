#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
double f(double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}
double k[5];
int len=0;
void cul(int x,int y)
{
	double l = (double)x;
	double r = (double)y;
	while(l<=r)
	{
		double mid = l + (r - l)/2;
		if(f(mid)<=0.00001&& f(mid)>=-0.00001)
		{
			k[++len] = mid;
			return;
		} 
		if(f(mid) * f(l) < 0) r = mid;//根在l和mid中间
		if(f(mid) * f(r) < 0) l = mid;//跟在r和mid中间
	}
	
}


int main()
{
	cin>>a>>b>>c>>d;
	for(int i=-100;i<=99;i++)
	{
		if(f(i) == 0) k[++len] = i;
		if(f(i)*f(i+1)<0) cul(i,i+1);
	}
	sort(k+1,k+4);
	for(int i=1;i<=3;i++) printf("%.2lf ",k[i]);
	
}