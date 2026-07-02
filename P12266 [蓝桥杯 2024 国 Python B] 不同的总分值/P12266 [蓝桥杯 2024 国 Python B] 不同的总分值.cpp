#include<bits/stdc++.h>
using namespace std;

int z[10] = {5,5,10,10,15,15,20,20,25,25};
int cnt;
set<int> vis;
int main()
{
	for(int a = 0;a <= 1;a++)
	{
		for(int b = 0;b <= 1;b++)
		{
			for(int c = 0;c <= 1;c++)
			{
				for(int d = 0;d <= 1;d++)
				{
					for(int e = 0;e <= 1;e++)
					{
						for(int f = 0;f <= 1;f++)
						{
							for(int g = 0;g <= 1;g++)
							{
								for(int h = 0;h <= 1;h++)
								{
									for(int i = 0;i <= 1;i++)
									{
										for(int j = 0;j <= 1;j++)
										{
											int num = z[0] * a + z[1] * b + z[2] * c + z[3] * d + z[4] * e + z[5] * f + z[6] * g + z[7] * h+ z[8] * i + z[9] * j;
											if(vis.count(num) == 0)
											{
												vis.insert(num);
												cnt++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << cnt << endl;
}
