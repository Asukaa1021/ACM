#include<bits/stdc++.h>
using namespace std;
string ans[1005];

string Add(string a,string b)
{
	string ans="";
	int carry=0;
	int n=a.size()-1;
	int m=b.size()-1;
	while(n>=0||m>=0||carry>0)
	{
		int c=0;
		if(n>=0)
		{
			c+=a[n]-'0';
			n--;
		}
		if(m>=0)
		{
			c+=b[m]-'0';
			m--;
		}
		if(carry>0)
		{
			c+=carry;
		}
		carry=c/10;
		c%=10;
		ans.push_back(c+'0');
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main()
{
	int m,n;
	cin>>m>>n;
	ans[m]="1",ans[m-1]="0";
	for(int i=m+1;i<=n;i++)
	ans[i]=Add(ans[i-1],ans[i-2]);
	
	cout<<ans[n];
}