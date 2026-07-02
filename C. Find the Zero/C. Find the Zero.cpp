#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	int ans;
	for(int i = 1;i < n;i++)
	{
		
		cout << "? " << i << " " << 2 * n - i + 1 << endl;
		cin >> ans;
		if(ans == 1)
		{
			cout << "! " << i << endl;
			return;
		}
	}
	cout << "? " << n - 1 << " " << n << endl;
	cin >> ans;
	if(ans == 1)
	{
		cout << "! " << n << endl;
		return;
	}
	cout << "? " << n << " " << n + 2 << endl;
	cin >> ans;
	if(ans == 1)
	{
		cout << "! " << n << endl;
		return;
	}
	cout << "! " << n + 1 << endl;
	return;
}

int main()
{
	int t;
	cin >> t;
	while(t--) solve();
}
