#include<bits/stdc++.h>
using namespace std;
int n,k;
int pos = 0;
int main()
{
	cin >> n >> k;
	for(int i = 2;i <= n;i++)
	{
		pos = (pos + k) % i;
	}
	cout << pos + 1 << endl;
}