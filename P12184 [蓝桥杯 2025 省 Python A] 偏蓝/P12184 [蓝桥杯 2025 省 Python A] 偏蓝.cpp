#include<bits/stdc++.h>
using namespace std;



int main()
{
	int ans = 0;
	for(int i = 0;i <= 255;i++)
	{
		for(int j = 0;j <= 255;j++)
		{
			for(int k = 0;k <= 255;k++)
			{
				if(k > i && k > j) ans++;
			}
		}
	}
	
	cout << ans << endl;
	
}