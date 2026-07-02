#include<bits/stdc++.h>
using namespace std;

string f[5002];

string Add(string a,string b)//高精度加法
{
	string c="";
	int I=a.size()-1;
	int J=b.size()-1;
	int carry=0;
	while(I>=0||J>=0||carry>0)
	{
		int sum=carry;
		if(I>=0) {
			sum+=a[I]-'0';
			I--;
		}
		if(J>=0)
		{
			sum+=b[J]-'0';
			J--;
		}
		carry=sum/10;
		sum=sum%10;
		c.push_back(sum+'0');
	}
	reverse(c.begin(),c.end());
	return c;
	
}

int main()
{
	int n;
	cin>>n;
	f[1]="1";
	f[2]="2";
	for(int i=3;i<=n;i++)
	{
		f[i]=Add(f[i-2],f[i-1]);
	}	
	cout<<f[n]<<endl;
}