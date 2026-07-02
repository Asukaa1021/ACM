#include<bits/stdc++.h>
using namespace std;

//SB做法
int main()
{
//	freopen("1.in", "r", stdin);
 //   freopen("1.out", "w", stdout);
	
	string s;
	int n=0;
	cin>>n;
	cin>>ws;
	getline(cin,s);
	bool t=1;

	int st2=0;

	for(int i=n;i>=0;i--)
	{
		int st1=st2;
		while(s[st2]!=' '&&st2<s.size())
		{
			st2++;
		}
		string k;
		k=s.substr(st1,st2-st1);

		
		if(k!="0"&&k!="-0"&&k!="+0")
		{
			if(t)
			{
				if(i>1)
				{
					if(k=="1"||k=="+1") cout<<"x^"<<i;
					else if(k=="-1")cout<<"-x^"<<i;
					else if(k[0]=='+')
					{
						k=k.substr(1,k.size()-1);
						cout<<k<<"x^"<<i;
					}
					else cout<<k<<"x^"<<i;
				}
				else if(i==1)
				{
					if(k=="1"||k=="+1") cout<<"x";
					else if(k=="-1")cout<<"-x";
					else if(k[0]=='+')
					{
						k=k.substr(1,k.size()-1);
						cout<<k<<"x";
					}
					else cout<<k<<"x";
				}
				else
				{
					if(k[0]!='+'&&k[0]!='-')
					{
					
						cout<<k;
					}
					else if(k[0]=='+')
					{
						k=k.substr(1,k.size()-1);
						cout<<k;
					}
					else cout<<k;
				}
				t=0;
			}
			else
			{
				if(i>1)
				{
					if(k=="+1") cout<<"+x^"<<i;
					else if(k=="1") cout<<"+"<<"x^"<<i;
					else if(k=="-1") cout<<"-x^"<<i;
					else if(k[0]!='+'&&k[0]!='-')
					{
						cout<<"+"<<k<<"x^"<<i;
					}
					else cout<<k<<"x^"<<i;
				}
				else if(i==1)
				{
					if(k=="+1") cout<<"+x";
					else if(k=="1") cout<<"+"<<"x";
					else if(k=="-1") cout<<"-x";
					else if(k[0]!='+'&&k[0]!='-')
					{
						cout<<"+"<<k<<"x";
					}
					else cout<<k<<"x";	
				}
				else
				{
					if(k[0]!='+'&&k[0]!='-') cout<<"+"<<k;
					else cout<<k;
				}
			}
			
		}
		st2++;
		
	}
	cout<<endl;
	return 0;
	
}
