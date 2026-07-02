#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b;

bool checks(int k)
{
	int p = (int)sqrt(k);
	if(p * p == k && k != 0) return true;
	return false;
}

bool check(int k)
{
	int p = (int)sqrt(k);
	if(p * p != k) return false;
	if(p <= 9) return true;
	string s = to_string(k);
	for(int i = 1;i <= s.size();i++)
	{
		int left,right;
		int p = 1;
		for(int j = 1;j <= i;j++) p = (p << 3) + (p << 1);
		left = k / p;
		right = k % p;
		if(checks(left) && checks(right)) return true;
	}
	return false;
}

signed main()
{
	cin >> a >> b;
	for(int i = a;i <= b;i++)
	{
		if(check(i)) cout << i << '\n';
	}
}
