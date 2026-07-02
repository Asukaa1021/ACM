#include<bits/stdc++.h>
using namespace std;

int len;
string Plus(int n,string num)
{
	string k="";
	int an[160000];
	memset(an,0,sizeof an);
	stringstream S;
	S<<n;
	S>>k;
	reverse(k.begin(),k.end());
	reverse(num.begin(),num.end());
	
	for(int i=0;i<k.size();i++)
	{
		for(int j=i;j<num.size();j++)
		{
			an[i+j]+=(k[i]-'0')*(num[j]-'0');
			an[i+j+1]+=(an[i+j])/10;
			an[i+j]%=10;
		}	
	}
	
	for(int i=150050;i>=0;i--)
	{
		if(an[i]!=0)
		{
			len=i;
			break;
		}
	}
	string answer="";
	for(int i=len;i>=0;i--)
	{
		char c=an[i]+'0';
		answer.push_back(c);
	}
	return answer;
}

int main()
{
	int Ans[150000];
	int T;
	cin>>T;
	for(int u=1;u<=T;u++)
	{
		int n;
		string ans="1";
		char a;
		cin>>n>>a;
		for(int i=1;i<=n;i++)
		{
			ans=Plus(i,ans);
		}
		int iCnt=0;
		for(int i=0;i<ans.size();i++)
		{
			if(ans[i]==a) iCnt++;
		}
		Ans[u]=iCnt;
	}
	
	for(int i=1;i<=T;i++)
	{
		cout<<Ans[i]<<endl;
	}
	return 0;
}