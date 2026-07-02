#include<bits/stdc++.h>
using namespace std;

#define int long long
int Max,sum;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int num;
		cin >> num;
		Max = max(Max,num);
		sum += num;
	}
	cout << min(sum / 3,sum - Max) << endl;
}