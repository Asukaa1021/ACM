#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<int> preS1(n + 1);
	vector<int> preS2(n + 1);
	for(int i = 1;i <= n;i++) 
	{
		cin >> a[i];
		preS1[i] = preS1[i - 1];
		if(a[i] == 1) preS1[i]++;
		preS2[i] = preS2[i - 1];
		if(a[i] == 2) preS2[i]++;
	//	cout << preS1[i] << '\n';
	}
	int pos = -1;
	int n1 = 0,n2 = 0;
	for(int i = 1;i < n;i++)
	{
		if(a[i] == 1 && pos == -1) n1++;
		if(a[i] == 2 && pos == -1) n2++;
		if(preS1[i] * 2 >= i)
		{
			if(pos == -1)
			{
				pos = i;
				while(a[i + 1] == 3 && preS1[i] * 2 >= i + 1 && i + 1 < n)
				{
					pos++;
					i++;
				}
				continue;
			}
		}
		if(pos != -1 && (preS1[i] - n1) * 2 + (preS2[i] - n2) * 2 >= i - pos)//        >=   2
		{
			cout << "Yes" << '\n';
			return;
		}
	}
	cout << "No" << '\n';
}

signed main()
{
	int t;
	cin >> t;
	while(t--) solve();
}