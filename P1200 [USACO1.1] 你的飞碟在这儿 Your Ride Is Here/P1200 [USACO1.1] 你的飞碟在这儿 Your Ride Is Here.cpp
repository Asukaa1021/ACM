#include<bits/stdc++.h>
using namespace std;



int main()
{
	string a,b;
	cin>>a>>b;
	int A=1,B=1;
	for(int i=0;i<a.size();i++)
	{
		A*=(a[i]-'A'+1);
		
	}
	for(int i=0;i<b.size();i++)
	{
		B*=(b[i]-'A'+1);
		
	}
	A%=47;
	B%=47;
	if(A==B) cout<<"GO"<<endl;
	else cout<<"STAY"<<endl;
	return 0;
}