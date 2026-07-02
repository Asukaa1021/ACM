#include<bits/stdc++.h>
using namespace std;
#define int long long
int p;
string k;
string mul(string a,string b)
{
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	if(a == "0" || b == "0") return "0";
	int lenA = a.size(),lenB = b.size();
	vector<int> num(55);
	for(int i = 0;i < lenA;i++)
	{
		for(int j = 0;j < lenB;j++)
		{
			int aa = a[i] - '0';
			int bb = b[j] - '0';
			
			num[i + j] += aa * bb;
			num[i + j + 1] += num[i + j] / 10;
			num[i + j] %= 10;
		}
	}
	int pos = 54;
	for(int i = 54;i >= 0;i--)
	{
		if(num[i] != 0)
		{
			pos = i;
			break;
		}
	}
	string ans = "";
	for(int i = pos;i >= 0;i--)	ans.push_back(num[i] + '0');
	
	return ans;
}

string ksm(string d,int z)
{
	if(z == 0) return "1";
	if(z % 2 == 0) return ksm(mul(d,d),z / 2);
	else return mul(d,ksm(mul(d,d),z / 2));
}

string _plus(string a,string b)
{
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int lenA = a.size(),lenB = b.size();
	vector<int> num(55);
	for(int i = 0;i < lenA || i < lenB;i++)
	{
		if(i < lenA) num[i] += a[i] - '0';
		if(i < lenB) num[i] += b[i] - '0';
		num[i + 1] += num[i] / 10;
		num[i] %= 10;
	}
	int pos = 54;
	for(int i = 54;i >= 0;i--)
	{
		if(num[i] != 0)
		{
			pos = i;
			break;
		}
	}
	string ans = "";
	for(int i = pos;i >= 0;i--)	ans.push_back(num[i] + '0');

	return ans;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> k >> p;
	vector<int> q(55);
	int len = 0;

	while(p > 0)
	{
		q[++len] = p % 2;
		p /= 2;
	}
	string ans = "0";
	for(int i = 1;i <= len;i++)
	{
		if(q[i] == 1)
		ans = _plus(ans,ksm(k,i - 1));
	}

	cout << ans << endl;
}
