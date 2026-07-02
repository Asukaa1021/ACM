#include<bits/stdc++.h>
using namespace std;

int n;
int F(int x)
{
	if(x==1) return 1;
	else return x*F(x-1);
}

int main()
{
	cin>>n;
	cout<<F(n)<<endl;
	
	
	return 0;
}