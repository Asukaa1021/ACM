#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int w,d,n;
	cin >> w >> d >> n;
	vector< vector<int> > po(n,vector<int> (3));
	for(int i = 0;i < n;i++) cin >> po[i][0] >> po[i][1] >> po[i][2];
	bool flag = true;
	long long ans = 0;
	for(int i = 1;i <= w;i++)
	{
		for(int j = 1;j <= d;j++)
		{
			int l = INT_MIN;
			int r = INT_MAX;
			for(auto & p : po)
			{
				int len = abs(p[0] - i) + abs(p[1] - j);
				l = max(l,p[2] - len);
				r = min(r,p[2] + len);
			}
			if(l > r) 
			{
				flag = false;
				break;
			}
			ans += l;
		}
		if(!flag) break;
	}
	if(flag)
	{
		cout << ans << endl;
	}
	else cout << "No" << endl;
}