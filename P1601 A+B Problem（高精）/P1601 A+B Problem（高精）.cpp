#include<bits/stdc++.h>
using namespace std;

string a,b;
string k;

string A(string x,string y)
{
	int i=x.size()-1;
	int j=y.size()-1;
	string ans="";
	int m=0;
	while(i>=0||j>=0||m)
	{
		int num=m;
		if(i>=0)
		{
			
			
			num+=x[i]-'0';
			i--;
		}
		if(j>=0)
		{
			num+=y[j]-'0';
			j--;
		}
		
		ans+=num%10+'0';
		m=num/10;
	}
	return ans;
}

int main()
{
	cin>>a>>b;
	k=A(a,b);
	reverse(k.begin(),k.end());
	cout<<k<<endl;
	return 0;	
}
