#include<bits/stdc++.h>
using namespace std;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	int l,q,sw;
	cin >> l >> q >> sw;
	if((l == q && l * 2 - 1 < sw) || min(l,q) * 2 < sw || (sw == 0 && min(l,q) > 0))
	{
		cout << -1 << endl;
		return 0;
	}
	if(sw % 2 == 0)
	{
		
		if(l > sw / 2)
		{
			for(int i = 1;i <= l - sw / 2 - 1;i++) cout << "L";
			for(int i = 1;i <= sw / 2;i++) cout << "LQ";
			for(int i = 1;i <= q - sw / 2;i++) cout << "Q";
			cout << "L";
			
		}
		else
		{
			cout << "Q";
			for(int i = 1;i <= sw / 2;i++) cout << "LQ";
			for(int i = 1;i <= q - sw / 2 - 1;i++) cout << "Q";
		}
	}
	else
	{
		for(int i = 1;i <= l - sw / 2 - 1;i++) cout << "L";
		for(int i = 1;i <= sw / 2 + 1;i++) cout << "LQ";
		for(int i = 1;i <= q - sw / 2 - 1;i++) cout << "Q";
	}
}
