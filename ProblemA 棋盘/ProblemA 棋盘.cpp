#include<bits/stdc++.h>
using namespace std;

long long num[3][200005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		long long sum = 0;
		for(int i = 1;i <= 2;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				cin >> num[i][j];
				sum += num[i][j];
			}
		}
		
		if(n % 2 == 1)
		{
			bool p1 = false,p2 = false;
			long long suml1 = 0,suml2 = 0,sumr1 = 0,sumr2 = 0,sump = 0,sumn = 0;
			for(int i = 1;i <= 2;i++)
			{
				for(int j = 1;j <= n / 2;j++)
				{
					suml1 += num[i][j];
				}
			}
			sumr1 = sum - suml1;
			if(suml1 > sumr1)
			{
				cout << "Mandy" << endl;
				continue;
			}
			if(suml1 == sumr1) p1 = true;
			
			
			for(int i = 1;i <= 2;i++)
			{
				for(int j = n / 2 + 2;j <= n;j++)
				{
					sumr2 += num[i][j];
				}
			}
			suml2 = sum - sumr2;
			for(int i = 1;i <= n;i++) sump += num[1][i];
			sumn = sum - sump;
			if(sumr2 > suml2 || sump < sumn)
			{
				if(!p1)
				cout << "brz" << endl;
				else 
				cout << "draw" << endl;
			}
			else if((sumr2 == suml2 || sump == sumn))
			{
				cout << "draw" << endl;
			}
			else cout << "Mandy" << endl;
		}
		else
		{
			bool p1 = false,p2 = false;
			long long suml1 = 0,suml2 = 0,sumr1 = 0,sumr2 = 0,sump = 0,sumn = 0;
			for(int i = 1;i <= 2;i++)
			{
				for(int j = 1;j <= n / 2;j++)
				{
					suml1 += num[i][j];
				}
			}
			sumr1 = sum - suml1;
			if(suml1 > sumr1)
			{
				cout << "Mandy" << endl;
				continue;
			}
			if(suml1 == sumr1) p1 = true;
			
			
			for(int i = 1;i <= 2;i++)
			{
				for(int j = n / 2 + 2;j <= n;j++)
				{
					sumr2 += num[i][j];
				}
			}
			suml2 = sum - sumr2;
			for(int i = 1;i <= n;i++) sump += num[1][i];
			sumn = sum - sump;
			if(sumr2 > suml2 || sump < sumn)
			{
				if(!p1)
				cout << "brz" << endl;
				else 
				cout << "draw" << endl;
			}
			else if((sumr2 == suml2 || sump == sumn))
			{
				cout << "draw" << endl;
			}
			else cout << "Mandy" << endl;
		}
	}
}