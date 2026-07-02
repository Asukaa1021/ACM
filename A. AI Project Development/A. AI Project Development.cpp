#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n,x,y,z;
	cin >> n >> x >> y >> z;
	int t1 = (n + x + y - 1) / (x + y);
	int t2 = INT_MAX;
	if(t1 > z)
	{
		int nn = n - x * z;
		t2 = (nn + x + 10 * y - 1) / (x + 10 * y);
		t2 += z;
	}
	cout << min(t1,t2) << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) solve();
}
