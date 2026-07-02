#include<bits/stdc++.h>
using namespace std;

bool vis[10];
int A,B,C;

int main()
{
	for(int a = 1;a <= 9;a++)
	{
		vis[a] = true;
		for(int b = 1;b <= 9;b++)
		{
			if(!vis[b]) vis[b] = true;
			else continue;
			for(int c = 1;c <= 9;c++)
			{
				if(!vis[c]) vis[c] = true;
				else continue;
				A = a * 100 + b * 10 + c;
				for(int d = 1;d <= 9;d++)
				{
					if(!vis[d]) vis[d] = true;
					else continue;
					for(int e = 1;e <= 9;e++)
					{
						if(!vis[e]) vis[e] = true;
						else continue;
						for(int f = 1;f <= 9;f++)
						{
							if(!vis[f]) vis[f] = true;
							else continue;
							B = d * 100 + e * 10 + f;
							for(int g = 1;g <= 9;g++)
							{
								if(!vis[g]) vis[g] = true;
								else continue;
								for(int h = 1;h <= 9;h++)
								{
									if(!vis[h]) vis[h] = true;
									else continue;
									for(int i = 1;i <= 9;i++)
									{
										if(!vis[i]) vis[i] = true;
										else continue;
										C = g * 100 + h * 10 + i;
										if(A * 2 == B && A + C == B * 2) cout << A << " " << B << " " << C << endl;
										vis[i] = false;
									}
									vis[h] = false;
								}
								vis[g] = false;
							}
							vis[f] = false;	
						}
						vis[e] = false;
					}
					vis[d] = false;
				}
				vis[c] = false;
			}
			vis[b] = false;
		}
		vis[a] = false;
	}
}