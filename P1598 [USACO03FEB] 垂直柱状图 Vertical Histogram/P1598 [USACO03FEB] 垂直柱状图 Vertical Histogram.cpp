#include<bits/stdc++.h>
using namespace std;

int num[50];
string s;
int n[50];

int main()
{
	for(int i=0;i<=3;i++)
	{
		getline(cin,s);
		for(int j=0;j<s.size();j++)
		{
			if(s[j]>='A'&&s[j]<='Z')
			{
				num[s[j]-'A'+1]++;
			}
		}
	}

	int Max=1;
	for(int i=1;i<=26;i++)
		if(num[i]>num[Max]) Max=i;
	for(int i=1;i<=num[Max];i++)

		for(int j=26;j>=1;j--)
		{
			if(num[j]>=i) 
			{
				n[i]=j;
				break;
			}
		}
	
	for(int i=1;i<=num[Max];i++)
	{
		for(int j=1;j<n[num[Max]-i+1];j++)
		{
			if((num[Max]-i+1)<=num[j])
				cout<<"*";
			else 
				cout<<" ";
				cout<<" ";
		}
		cout<<"*";
		cout<<endl;
	}
	for(int i=1;i<=25;i++)
	{
		char t='A'-1;
		t+=i;
		cout<<t<<" ";
		
	}
	cout<<"Z";
	return 0;
}