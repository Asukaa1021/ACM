#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b;
int n,ans;
signed main()
{
	cin >> a >> b;
	for(int i = 1;i <= 50;i++)
	{
		if(i * (1 + i) / 2 == a + b)
		{
			n = i;
			break;
		}
	}
	int h = n;
	for(int k = 0;k < (1 << h);k++)//底层
	{
		int temp = k;
		int cnt_a = __builtin_popcountl(temp);
		int cnt_b = h - cnt_a;
		for(int i = h - 1;i >= 1;i--)
		{
			int temp2 = 0;
			for(int j = 1;j <= i;j++)
			{
				int num1 = ((1 << (j)) & temp);
				int num2 = ((1 << (j - 1)) & temp);
				
				if((num1 > 0 && num2 > 0) || (num1 == 0 && num2 == 0))
				{
					temp2 += (1 << (j - 1));
					cnt_a++;
				}
				else cnt_b++;
			}
			temp = temp2;
		}
		if(cnt_a <= a && cnt_b <= b) ans++;
	}	
	cout << ans << endl;
}
