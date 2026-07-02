#include<bits/stdc++.h>
using namespace std;

int sz[105];

int main()
{
	int n,g;
	cin >> n;
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		int num;
		cin >> num;
		if(num < 0) sz[abs(num)] = -1;
		else sz[num] = 1;
		if(i == 1) g = abs(num);
	}
	if(sz[g] < 0)
	{
		for(int i = 1;i < g;i++)
			if(sz[i] == 1) cnt++;
			
		if(cnt > 0)
			for(int i = g + 1;i <= 99;i++)
				if(sz[i] == -1) cnt++;
	}
	else
	{
		for(int i = g + 1;i <= 99;i++)
			if(sz[i] == -1) cnt++;
		
		if(cnt > 0)
			for(int i = 1;i < g;i++)
				if(sz[i] == 1) cnt++;
	}
	cout << cnt + 1 << endl;
}
