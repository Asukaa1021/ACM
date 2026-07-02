#include<bits/stdc++.h>
using namespace std;

unordered_map<int,char> mp;

void f(int a,int b,int n)
{
	stack<char> stk;
	int ab = a * b;
	int num = 0;
	while(ab > 0)
	{
		stk.push(mp[ab % n]);
		ab /= n;
	}
	while(!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0;i <= 9;i++) mp[i] = (char)('0' + i);
	for(int i = 10;i < n;i++) mp[i] = (char)('A' + i - 10);
	for(int i = 1;i < n;i++)
	{
		for(int j = 1;j <= i;j++)
		{
			cout << mp[i] << '*' << mp[j] << '=';
			f(i,j,n);
			cout << ' ';
		}
		cout << endl;
	}
}