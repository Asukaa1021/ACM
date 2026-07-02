#include<bits/stdc++.h>
using namespace std;
int main()
{
	set<int> a;
	int n;
	cin>>n;
	int b;
	int p=1;
	
	for(int i=1;i<=n;i++)
	{
		cin>>b;
		a.insert(b);
		
		
	}
	int k=a.size();
	cout<<k<<endl;
	for(auto i=a.begin();i!=a.end();i++)
	
	{
		cout<<*i;
		
		if(p++!=k)
		cout<<" ";
		}	
		
	
	return 0;
}