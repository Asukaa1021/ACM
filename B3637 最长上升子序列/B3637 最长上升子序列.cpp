#include<bits/stdc++.h>
using namespace std;

int n;
int main()
{
	cin >> n;
	vector<int> a(n + 1),b(n + 1);
	for(int i = 1;i <= n;i++) cin >> a[i];
	b[1] = a[1];
	int len = 1;
	for(int i = 2;i <= n;i++)
	{
		if(a[i] > b[len])
		{
			b[++len] = a[i];
		}
		else
		{
			int j = lower_bound(b.begin() + 1,b.begin() + 1 + len,a[i]) - b.begin();
			b[j] = a[i];
		}
	}
	cout << len << endl;
}