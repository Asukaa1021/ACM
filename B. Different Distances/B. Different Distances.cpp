#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	if(n % 2 == 0)
	{
		//2 * cnt
		int cnt = n / 2;
		for(int i = 1;i <= n;i += 2)
		{
			cout << i + 0 << ' ' << i + 1 << ' ' << i + 0 << ' ' << i + 0 << ' ' 
				 << i + 1 << ' ' << i + 1 << ' ' << i + 0 << ' ' << i + 1 << ' ';
		}
	}
	else
	{
		int cnt = n / 2;
		cnt--;
		//2 * cnt  + 1 * 3    1 1 2 1 2 3 1 3 2 2 3 3
		cout << 1 << ' ' << 1 << ' ' << 2 << ' ' << 1 << ' ' 
			 << 2 << ' ' << 3 << ' ' << 1 << ' ' << 3 << ' '
			 << 2 << ' ' << 2 << ' ' << 3 << ' ' << 3 << ' ';
		for(int i = 4;i <= n;i += 2)
		{
			cout << i + 0 << ' ' << i + 1 << ' ' << i + 0 << ' ' << i + 0 << ' ' 
				 << i + 1 << ' ' << i + 1 << ' ' << i + 0 << ' ' << i + 1 << ' ';
		}
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) solve();
}
