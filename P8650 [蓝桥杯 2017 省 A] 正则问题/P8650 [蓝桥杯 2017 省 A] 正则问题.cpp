#include<bits/stdc++.h>
using namespace std;
int dfs(void)
{
	int cnt = 0;
	char c;
	while(cin >> c)
	{
		if(c == 'x') cnt++;
		if(c == '(') cnt += dfs();
		if(c == ')') return cnt;
		if(c == '|') return max(cnt,dfs());
	}
	return cnt;
}

int main()
{
	cout << dfs() << endl;
}
