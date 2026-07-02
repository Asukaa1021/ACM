#include<bits/stdc++.h>
using namespace std;
long long cnt;
int a[10] = {0,1,2,3,4,5,6,7,8,9};
int main()
{
	int n,cnt = 0 ;
	cin >> n;
	do
	{
		for(int i = 1;i < 9;i++)
		{
			for(int j = i + 1;j < 9;j++)
			{
				int num1 = 0,num2 = 0,num3 = 0;
				
				for(int k = i + 1;k <= j;k++)
				{
					num2 *= 10;
					num2 += a[k];
				}
				for(int k = j + 1;k <= 9;k++)
				{
					num3 *= 10;
					num3 += a[k];
				}
				if(num2 % num3 != 0) continue;
				int p = num2 / num3;
				for(int k = 1;k <= i;k++)
				{
					num1 *= 10;
					num1 += a[k];
				}
				if(p + num1 == n) cnt++;
			}
		}
	}while(next_permutation(a + 1,a + 1 + 9));
	cout << cnt << endl;
}