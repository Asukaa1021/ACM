#include<bits/stdc++.h>
using namespace std;

int N,m,a[10005];

void Input()
{
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>a[i];
}

int Cut()
{
	int ans=0;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N-i;j++)
		if(a[j]>a[j+1])
		{
			swap(a[j+1],a[j]);
			ans++;
		}
	}
	return ans;
}

int main()
{
	Input();
	cout<<Cut();
	
	return 0;
	
}