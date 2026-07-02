#include<bits/stdc++.h>
using namespace std;
int w;
int main()
{
	string sen;
	string str;
	getline(cin,str);
	getline(cin,sen);
	sen=' '+sen+' ';
	int count=0;
	for(int i=0;i<sen.size();i++)
	{
		if(sen[i]<='Z'&&sen[i]>='A') 
			sen[i]+='a'-'A';
	}
	
	for(int i=0;i<str.size();i++)
	{
		if(str[i]<='Z'&&str[i]>='A') 
			str[i]+='a'-'A';
	}

	
		int i=1;
		bool k=1;
		if(sen.find(str,i)!=string::npos)
		{
			i=sen.find(str,i);
		}
		while(sen.find(str,i)!=string::npos)
		{	
			i=sen.find(str,i);
			if(sen[i-1]==' '&&sen[i+str.size()]==' ')//保证前后为空格
			{
				if(k==1)
				{
					w=sen.find(str,i);
					k=0;
				}
			count++;
			
			}
			i=sen.find(str,i)+str.size();//向后跳格
		}
		if(count==0)
		{
			cout<<"-1"<<endl;
		}
		else{
			cout<<count<<" "<<--w<<endl;
		}
		

	
	
	return 0;
}
