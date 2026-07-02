#include<bits/stdc++.h>
using namespace std;

int n;
long long a[1005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	multiset<long long> st;
	cin >> n;
	
	for(int i = 1;i <= n;i++) cin >> a[i],a[i] = a[i - 1] + a[i];
	long long Min = LONG_MAX;
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			st.insert(a[j] - a[i - 1]);
		}
	}
	for(int i = 1;i < n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			auto k = a[j] - a[i - 1];
			auto p = st.find(k);
			st.erase(p);
		}
		for(int j = 1;j <= i;j++)
		{
			auto k = a[i] - a[j - 1];
			auto p = st.lower_bound(k);
			if(p != st.end()) Min = min(Min,abs(*p - k));
			if(p != st.begin()) p--,Min = min(Min,abs(*p - k));
		}
	}
	cout << Min << endl;
}