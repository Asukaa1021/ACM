#include<bits/stdc++.h>
using namespace std;


int main()
{
	string a,b;
	long long ans = 1;
	cin >> a >> b;
	for(int i = 0;i < a.size() - 1;i++)
	{
		for(int j = 1;j < b.size();j++)
		{
			if(a[i] == b[j] && a[i + 1] == b[j - 1]) ans *= 2;
		}
	}
	cout << ans << endl;
}