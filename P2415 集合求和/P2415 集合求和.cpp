#include<bits/stdc++.h>
using namespace std;
int k[33];
int main()
{
	long long a=0;
	stringstream S;
	
	string m;
	int len=0;
	while(cin>>m)
	{
		
		if(m=="\n") break;
		S.clear();
		S<<m;
		
		S>>k[++len];
	}
	for(int i=1;i<=len;i++)
	{
		a+=(long long)pow(2,len-1)*k[i];
		
	}
	cout<<a<<endl;
	return 0;
}