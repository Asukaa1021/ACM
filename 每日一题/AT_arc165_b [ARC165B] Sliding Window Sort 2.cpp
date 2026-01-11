#include<bits/stdc++.h>
using namespace std;
#define N 200005
int n,k,p[N],tag;
queue<pair< int , int >> q;
void print()
{
	for(int i = 1; i <= n ;i++)	cout<< p[i] <<" ";
}

int main()
{
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin>>p[i];
	if(n == k)
	{
		sort(p + 1,p + 1 + n);
		print();
		return 0;
	}
	int cnt = 0;
	for(int i = 1;i <= n ;i++)
	{
		if(p[i] > p[i-1]) cnt++;
		else cnt = 1;
		if(cnt >= k)
		{
			print();
			return 0;
		}
	}
	
	int e = n - 2 * k + 1;
	if(e < 1) e = 1;
	tag = n - k ;
	for(int  i = n - k - 1;i >= e; i--)
	{
		if(p[i + 1] > p[i]) tag = i;//从哪里开始
		else break;
	}
	
	bool pd = true;
	for(int i = n - k + 1; i <= tag + k - 1;i++)
	{
		if( p[i] < p[n - k])
		{
			pd = false ;
			break;
		}
	}
	
	if(pd)	sort(p + tag , p + 1 + tag + k -1);
	else 	sort(p + n - k + 1 ,p + 1 + n);	
	print();
}