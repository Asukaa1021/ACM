#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int k = n - 2013 + 1;
	if(k >= 7)
	{
		if(k != 10) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else cout << "No" <<endl;
}