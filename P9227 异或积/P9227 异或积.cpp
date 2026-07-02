#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		int cur_xor = 0;
		vector<int> num(n);
		for(int i = 0;i < n;i++)
		{
			cin >> num[i];
			cur_xor ^= num[i];
		} 
		if(k % 2 == 1) 
			for(int i = 0;i < n;i++)
			{
				num[i] = cur_xor ^ num[i];

			}
		else
		{
			int new_xor = 0;
			for(int i = 0;i < n;i++)
			{
				num[i] = cur_xor ^ num[i];
				new_xor ^= num[i];
			}
			for(int i = 0;i < n;i++)
				num[i] = new_xor ^ num[i];
		}
		for(int i = 0;i < n;i++)
		{
			cout << num[i] << " ";
		} 
		cout << endl;
	}
	
	
}
