#include<bits/stdc++.h>
using namespace std;

string s;
int a1=0,b1=0;
int a2=0,b2=0;

char ans[2600][30];
int k=0;

int main()
{
	while(cin>>s)
	{
		for(int i=0;i<s.size();i++)
		{
			
			if(s[i]=='W'){
				a1++;
			}
			if(s[i]=='L'){
				b1++;
			}
			if(((a1>=11||b1>=11)&&(abs(a1-b1)>=2))||s[i]=='E')
			{

				cout<<a1<<":"<<b1<<endl;
				a1=0;
				b1=0;
			}
		}
		
		for(int i=0;i<s.size();i++)
		{
			
			if(s[i]=='W'){
				a2++;

			}
			if(s[i]=='L'){
				b2++;
	
			}
			if(((a2>=21||b2>=21)&&(abs(a2-b2)>=2))||s[i]=='E')
			{

				sprintf(ans[++k],"%d:%d",a2,b2);
				a2=0;
				b2=0;
			}
		}
		
		
	}

	cout<<endl;
	for(int i=1;i<=k;i++)
	{
		printf("%s\n",ans[i]);
	}
	
	return 0;
}
