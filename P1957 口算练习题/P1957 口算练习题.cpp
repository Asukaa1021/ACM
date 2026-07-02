#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	int a,b;
	string s;
	char flag;
	
	char s2[1005];
	stringstream S;
	cin>>T;
	while(T--)
	{
		cin>>s;
		if(s[0]>='a'&&s[0]<='c')
		{
			flag=s[0];
			cin>>a>>b;
		}
		else{
			S.clear();
			S<<s;
			S>>a;
			cin>>b;
		}
		if(flag=='a')
		{
			sprintf(s2,"%d+%d=%d",a,b,a+b);
			cout<<s2<<endl<<strlen(s2)<<endl;
		}
		else if(flag=='b')
		{
			sprintf(s2,"%d-%d=%d",a,b,a-b);
			cout<<s2<<endl<<strlen(s2)<<endl;
		}
		else {
			sprintf(s2,"%d*%d=%d",a,b,a*b);
			cout<<s2<<endl<<strlen(s2)<<endl;
		}
	}
	
	
	return 0;
}