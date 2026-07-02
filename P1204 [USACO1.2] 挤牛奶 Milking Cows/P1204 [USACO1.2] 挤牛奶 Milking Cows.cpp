#include<bits/stdc++.h>
using namespace std;

int t[1000005];
int tMax = 0;
int main()
{
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int a,b;
		cin >> a >> b;
		t[a]++;
		t[b]--;
		tMax = max(tMax,b);
	}
	int temp = 0;
	bool isok =  false;
	int len = 0,len2 = 0;
	int ans = 0,ans2 = 0;
	for(int i = 0;i < tMax;i++)
	{
		temp += t[i];
		if(temp > 0) isok = true;
		if(temp > 0) len++;
		else len = 0;
		ans = max(ans,len);
		if(isok)
		{
			if(temp <= 0) len2++;
			else len2 = 0;
			ans2 = max(ans2,len2);
		}
	}
	cout << ans << " " << ans2 << endl;
}
