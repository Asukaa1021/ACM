#include<bits/stdc++.h>
using namespace std;
char pid;
long long ans = 0;
void dfs(int depth,int cnt)
{
	if(cnt == 7) ans++;
	if(depth >= 30 || cnt == 10) return;
	depth++;
	dfs(depth,cnt + 1);
	dfs(depth,0);
}

int main() {
    cin >> pid;
    if(pid == 'A')
        puts("4430091");
    else
    {
		dfs(0,0);
		cout << ans << endl;
	}
    return 0;
}