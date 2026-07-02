#include<bits/stdc++.h>
using namespace std;

struct Stu
{
	int xh;
	int xy;
	int tz;
	int z;
};

bool cmp(int a,int b);

int main()
{
	Stu k[1005];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i].xh>>k[i].xy>>k[i].tz;
		k[i].z=k[i].xy*7+k[i].tz*3;
		if((k[i].xy+k[i].tz)>140&&k[i].z>=800)
		cout<<"Excellent"<<endl;
		else cout<<"Not excellent"<<endl;
	}	
	return 0;
}

bool cmp(int a,int b)
{
	if(a>=b) return a;
	else return b;
}