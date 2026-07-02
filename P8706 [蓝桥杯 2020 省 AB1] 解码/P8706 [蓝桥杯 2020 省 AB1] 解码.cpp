#include<bits/stdc++.h>
using namespace std;


int main()
{
	string a;
	cin >> a;
	for(int i = 0;i < a.size();i++)
	{
		if(isdigit(a[i]))
		{
			for(int j = 1;j < (a[i] - '0');j++) cout << a[i - 1];
		}
		else cout << a[i];
	}
}