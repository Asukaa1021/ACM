#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		for(int i = 1;i <= m;i++)
		{
			if(n % i != i - 1)
			{
				cout << "Yes" << endl;
				goto e;
			}
		}
		cout << "No" << endl;
		e:;
	}	
}