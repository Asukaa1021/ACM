#include<bits/stdc++.h>
using namespace std;

int color(int x)
{
	if(x == 1) return 1;
	else
	{
		int fa = x / 2;
		if(x == fa * 2) //left
			return color(fa);
		else //right
			return 1 - color(fa);
	}
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		int num = (1 << n) - (1 << (n - 1)) + m - 1;
		if(color(num) == 1) cout << "RED" << endl;
		else cout << "BLACK" << endl;
	}
	
}

