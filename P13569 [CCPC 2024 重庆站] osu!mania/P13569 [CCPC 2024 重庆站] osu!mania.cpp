#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);     cout.tie(0); 
	int T;
	cin>>T;
	while(T--) {
		double maxpp,a,b,c,d,e,f;
		cin>>maxpp>>a>>b>>c>>d>>e>>f;
		double acc=300*a+300*b+200*c+100*d+50*e+0*f;
		acc/=300*(a+b+c+d+e+f);acc*=100;
		acc*=100;acc=int(acc+0.5000000001);acc/=100;
		cout<<fixed<<setprecision(2)<<acc<<'%'<<' ';
		double pp=320*a+300*b+200*c+100*d+50*e+0*f;
		pp/=320*(a+b+c+d+e+f);pp-=0.80;
		pp=max(0.00,pp);pp*=5;pp*=maxpp;
		pp+=0.5000000001;pp=(int)pp;
		cout<<fixed<<setprecision(0)<<pp<<'\n';
	}
	return 0;
} 
