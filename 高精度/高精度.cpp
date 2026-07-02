#include<bits/stdc++.h>
using namespace std;

string a,b,c;
int A[100],B[100],C[100];

int main()
{
	
	cin>>a>>b;
	int len1,len2,len;
	len1=a.size();
	len2=b.size();
	if(len1>=len2) len=len1;
	else len = len2;
	
	
		
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	
	for(int i=0;i<=len1-1;i++)
	A[i]=a[i]-48;
	
	for(int i=0;i<=len2-1;i++)
	B[i]=b[i]-48;
	
	if(B[len-1]+A[len-1]>=10) len++;
	
	for(int i=1;i<=len;i++)
	{
		C[i]+=(A[i-1]+B[i-1])%10;
		C[i+1]+=(A[i-1]+B[i-1])/10;
	}
	
	
	for(int i=1;i<=len;i++) cout<<C[len-i+1];
	
	
	return 0;
}