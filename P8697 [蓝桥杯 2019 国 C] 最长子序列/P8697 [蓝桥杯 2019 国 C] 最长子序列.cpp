#include<bits/stdc++.h>
using namespace std;

string a,b;
long long dp[1005][1005];
int main()
{
	cin >> a >> b;
	int lena = a.size(),lenb = b.size();
	a = " " + a;
	b = " " + b;
	long long ans = 0;
	
	for(int i = 1;i <= lenb;i++)
	{
		for(int j = 1;j <= lena;j++)
			if(b[i] == a[j]) 
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else 
				dp[i][j] = dp[i][j - 1];

		if(dp[i][lena] != i) break;
		ans = i;
	}
	
	cout << ans << endl;
}
