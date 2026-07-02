#include<bits/stdc++.h>
using namespace std;

int n;
bool f(int x)
{
	if(x==2) return 1;
	if(x%2==0) return 0;
	for(int i=3;i<sqrt(x+1);i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}

int main()
{
	cin>>n;
	for(int i=4;i<=n;i+=2)
	{
		for(int j=2;j<=i/2;j++)
		{
			if(f(j)&&f(i-j)) 
			{
				cout<<i<<'='<<j<<"+"<<i-j<<endl;
				break;
			}
		}
		
	}
	
	
	
	return 0;
}