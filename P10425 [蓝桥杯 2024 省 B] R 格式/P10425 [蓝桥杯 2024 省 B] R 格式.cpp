#include<bits/stdc++.h>
using namespace std;

string Plus(string a,string b)
{
	int alen = a.size(),blen = b.size();
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	vector<int> ans(50000);
	for(int i = 0;i < alen;i++)
	{
		for(int j = 0;j < blen;j++)
		{
			int aa = a[i] - '0';
			int bb = b[j] - '0';
			int c = aa * bb + ans[i + j];
			ans[i + j] = c % 10;
			ans[i + j + 1] += c / 10;
		}
	}
	string k;
	int pos = 0;
	for(int i = 49999;i >= 0;i--)
	{
		if(ans[i] != 0)
		{
			pos = i;
			break;
		}
	}
	for(int i = pos;i >= 0;i--) k.push_back('0' + ans[i]);
	//reverse(k.begin(),k.end());
	return k.empty() ? "0" : k;
}
string ksm(string d,int z)
{
	if(z == 1) return d;
	if(z == 0) return "1";
	if(z % 2 == 0) return ksm(Plus(d,d),z / 2);
	return Plus(d,ksm(Plus(d,d),z / 2));
}
string add(string a)
{
	int alen = a.size();
	reverse(a.begin(),a.end());
	vector<int> ans(50005);
	a[0]++;
	for(int i = 0;i < alen;i++)
	{
		int k = a[i] - '0' + ans[i];
		ans[i] = k % 10;
		ans[i + 1] += k / 10;
	}
	string k;
	int pos = 0;
	for(int i = 49999;i >= 0;i--)
	{
		if(ans[i] != 0)
		{
			pos = i;
			break;
		}
	}
	for(int i = pos;i >= 0;i--) k.push_back('0' + ans[i]);
	return k.empty() ? "0" : k;
}

int main()
{
	int n;
	string d;
	cin >> n >> d;
	string d2;
	int pos;
	bool flag = false;
	int dis = d.size() - d.find(".") - 1;//小数点后位数
	for(int i = 0;i < d.size();i++)
	{
		if(d[i] != '.')
		{
			if(d[i] != '0') flag = true;
			if(flag) d2.push_back(d[i]);
		 } 
	}
	
	string a = ksm("2",n);
	string ans = Plus(a,d2);
	string ans2;
	int len = ans.size();
	if(len - dis >= 0)
		ans2 = ans.substr(0,len - dis);
	else ans2 = "0";
	if(ans[len - dis] >= '5')
	{
		cout << ans[len - dis] << endl;
		cout << add(ans2) << endl;	
		 } 	
	else
	{
		cout << ans[len - dis] << endl;
		cout << ans2 << endl;
	}
}