#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int x,y;
	cin >> x >> y;
	if((x + y) % 2 == 0) x--;
	else y--;
	int a = x;
	int b = y - x;
	if(a < 0 || b < 0) 
	{
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';

	for(int i = 2;i <= 1 + b;i++)
	{
		cout << 1 << ' ' << i << '\n';
	}
	for(int i = 2 + b;i <= 1 + b + a;i++)
	{
		cout << 1 << ' ' << i << '\n';
		cout << i << ' ' << i + a << '\n';
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--) solve();
}