#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string word;
	cin>>n;
	cin>>word;
	while(n--)
	{
		int k;
		cin>>k;
		if(k==1||k==4)
		{
			string ans=word;
			string str;
			cin>>str;
			if(k==1)
			{
				word=word+str;//相加
				cout<<word<<endl;
			}
			if(k==4)
			{
				
				size_t pos=word.find(str);//查找子串
				if(pos!=string::npos)
				{
					cout<<pos<<endl;
				}
				else {
					cout<<"-1"<<endl;
				}
			}
			
		}
		if(k==2)
			{
				int a,b;
				cin>>a>>b;
				word=word.substr(a,b);//截取子串
				cout<<word<<endl;
			}
			if(k==3)
			{
				int a;
				string p;
				cin>>a>>p;
				word=word.insert(a,p);//插入子串
				cout<<word<<endl;
			}
	}
	return 0;
}