#include<bits/stdc++.h>
using namespace std;

int n;
long long jf;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	vector< vector<int> > wheel(3,vector<int> (n));
	for(int i = 0 ;i < 3;i++)
	{
		for(int j = 0;j < n;j++)
		{
			cin >> wheel[i][j];
		}
	}
	int q;
	int p1 = 0,p2 = 0,p3 = 0;
	cin >> q;
	while(q--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		p1 += a;p1 %= n;
		p2 += b;p2 %= n;
		p3 += c;p3 %= n;
		int num1 = max(max(wheel[0][p1],wheel[1][p2]),wheel[2][p3]);
		int num3 = min(min(wheel[0][p1],wheel[1][p2]),wheel[2][p3]);
		int num2 = wheel[0][p1] + wheel[1][p2] + wheel[2][p3] - num1 - num3;
		if(num1 == num2 && num2 == num3) jf += 200;
		else if(num1 == num2 || num2 == num3 || num1 == num3) jf += 100;
		else if(num3 + 1 == num2 && num2 + 1 == num1)
		{
			if(num3 == wheel[0][p1] && num2 == wheel[1][p2] && num1 == wheel[2][p3]) jf += 200;
			else jf += 100;
		}
	}
	cout << jf << endl;
}