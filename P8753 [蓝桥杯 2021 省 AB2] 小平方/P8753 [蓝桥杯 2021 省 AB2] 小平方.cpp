#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 1;i < n;i++)
	{
		int num = i * i % n;
		if(num * 2 < n) cnt++;
	}
	cout << cnt << endl;
}