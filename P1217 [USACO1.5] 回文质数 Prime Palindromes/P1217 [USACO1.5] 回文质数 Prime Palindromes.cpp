#include<bits/stdc++.h>
using namespace std;

bool f(int x)
{
	if(x==1) return 0;
	if(x%2==0||x%3==0) return 0;
	for(int i=5;i<=sqrt(x+1);i+=2)
	{
		if(x%i==0) return 0;
	}
	return 1;
}

int main()
{
	stringstream S;
	string a,b;
	
	int x,y;
	cin>>x>>y;
	if(x%2==1)
	for(int i=x;i<=y&&i<10000000;i+=2)
	{
		
		S.clear();
			S<<i;
			S>>a;
			b=a;
			reverse(b.begin(),b.end());
			if(a==b){
				if(f(i))
				{
					cout<<i<<endl;
				}
		}
		
		
	}
	else 
		for(int i=x+1;i<=y&&i<10000000;i+=2)
	{
		S.clear();
			S<<i;
			S>>a;
			b=a;
			reverse(b.begin(),b.end());
			if(a==b)
			{
				if(f(i))
				{
					if(a==b) cout<<i<<endl;
				}
			}
	}
	
	
	return 0;
}