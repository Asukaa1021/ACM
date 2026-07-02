#include<bits/stdc++.h>
using namespace std;


void solve()
{
	int n;
	string s;
	cin >> n >> s;
	bool ok = true;
	bool curr = (s[0] == '1');
	int cnt = 0;
	for(int i = 0;i < n;i++)
	{
		if(s[i] == '0') cnt++;
		if(i == 0) continue;
		if(s[i] == '0' && s[i - 1] == '0') curr = false;
		if(s[i] == '1' && s[i - 1] == '1')
		{
			if((cnt & 1) && curr)
			{
				ok = false;
				break;
			}
			cnt = 0;
			curr = true;
		}
	}
	if((cnt & 1) && curr && s[n - 1] == '1') ok = false;
	cout << (ok ? "Yes" : "No") << '\n';
}

int main()
{
	int t;
	cin >> t;
	while(t--) solve();
}
