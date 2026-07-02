#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(int x)
{
	return sqrt(x / 2 + 1);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> num(n);
	for(int i = 0;i < n;i++)
	{
		int k;
		cin >> k;
		num[i].push_back(k);
		while(num[i][num[i].size() - 1] > 1)
			num[i].push_back(f(num[i][num[i].size() - 1]));
	}
	int cnt = 0,cnt2 = 1;
	while(cnt2 > 0)
	{
		int i = 0;
		cnt2 = 0;
		while(i < n)
		{
			if(num[i].size() == 1)
			{
				i++;
				continue;	
			 } 
			int a = num[i][num[i].size() - 1];
			int j = i;int prev = -1;
			while(j < n && num[j].size() != 1 && num[j][num[j].size() - 1] == a)
			{
				num[j].pop_back();
				if(prev == num[j][num[j].size() - 1]) cnt--;
				prev = num[j][num[j].size() - 1];
				j++;
				cnt++;
			}
			cnt2++;
			i = j;
		}
	}
	cout << cnt << endl;
}