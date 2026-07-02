#include<bits/stdc++.h>
using namespace std;
int stk[55];
int len=0;
int main()
{
	char c;
	int num=0;
	while(cin>>c)
	{
		if(c=='@') break;
		else if(c>='0'&&c<='9') num=num*10+c-'0';
		else if(c=='.') 
		{
			stk[++len]=num;
			
			num=0;
		}
		else if(c=='+') 
		{
			stk[len-1]=stk[len]+stk[len-1];
			stk[len]=0;
			len--;
		}
		else if(c=='-') 
		{
			stk[len-1]=stk[len-1]-stk[len];
			stk[len]=0;
			len--;
		}
		else if(c=='*') 
		{
			stk[len-1]=stk[len-1]*stk[len];
			stk[len]=0;
			len--;
		}
		else if(c=='/') 
		{
			stk[len-1]=stk[len-1]/stk[len];
			stk[len]=0;
			len--;
		}
	}

	cout<<stk[1]<<endl;
	
}