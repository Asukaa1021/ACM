#include<bits/stdc++.h>
using namespace std;

struct amb
{
	int l,r;
	int bi;
}a[1005];

bool cmp(amb a,amb b)
{
	return a.bi < b.bi;
}

string Plus(string c,string b)
{
	if(c=="0"||b=="0") return "0";
	int lenc=c.size();
	int lenb=b.size();
	vector<int> result(lenc+lenb,0);
	for(int i=lenc-1;i>=0;i--)
	{
		for(int j=lenb-1;j>=0;j--)
		{
			int num=(c[i]-'0')*(b[j]-'0')+result[i+j+1];
			result[i+j+1]=num%10;
			result[i+j]+=num/10;
		}
	}
	string res;
	for(int i=0;i<result.size();i++)
	{
		if(!(res.empty() && result[i]==0))
		{
			res.push_back(result[i]+'0');
		}
	}
	
	return res;
}

string maxString(string b,string c)
{
	if(b.size()!=c.size())
	{
		return (b.size()>c.size()) ? b : c;
	}
	else
	{
		for(int i=0;i<b.size();i++)
		{
			if(b[i]==c[i]) continue;
			else return (b[i]>c[i]) ? b : c;
		}
	}
	return b;
}

string div(string a,int b)//
{
	if(a=="0") return "0";
	if(b==1) return a;
	if(b==0) return "ERROR";
	
	string quotient;
	long long left=0;
	
	for(int i=0;i<a.size();i++)
	{
		int digit = a[i]-'0';
		left = left * 10 + digit;
		
		int qu = left / b;
		
		quotient.push_back(qu + '0');
		left%=b;
	}
	string new_quotient;
	for(int i=0;i<quotient.size();i++)
	{
		if(!(quotient[i] == '0' && new_quotient.empty()))//删除前导零
		{
			new_quotient.push_back(quotient[i]);
		}
	}
	if(new_quotient.empty()) return "0";
	return new_quotient;
}

int main()
{
	int n;
	int kl,kr;
	cin>>n>>kl>>kr;
	for(int i=1;i<=n;i++)
	{
		cin>> a[i].l >> a[i].r;
		a[i].bi=a[i].r*a[i].l;
	}
	
	sort(a+1,a+1+n,cmp);
	stringstream S;
	S.clear();
	S<<kl;
	string ans="0",sum;
	S>>sum;
	for(int i=1;i<=n;i++)
	{
		S.clear();
		S<<a[i].l;
		string c;
		S>>c;
		sum=Plus(sum,c);
		ans=maxString(div(sum,a[i].bi),ans);
	}
	cout<<ans<<endl;
}