#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> board;
bool check()
{
	bool flg = false;
	for(int i = 1;i <= 3;i++)
	{
		if(board[i][1] == 1 && board[i][2] == 1 && board[i][3] == 1) return true;
		if(board[1][i] == 1 && board[2][i] == 1 && board[3][i] == 1) return true;
	}	
	if(board[1][1] == 1 && board[2][2] == 1 && board[3][3] == 1) return true;
	if(board[3][1] == 1 && board[2][2] == 1 && board[1][3] == 1) return true;
	return false;
}

void solve()
{
	int n,fx,fy,ansx = -1,ansy = -1;
	cin >> n;
	board.clear();
	board.resize(4,vector<int> (4,0));
	for(int i = 1;i <= n;i++)
	{
		int r,c;
		cin >> r >> c;
		board[r][c] = 1;
		if(i == 1) 
			fx = r,fy = c;
	}
	for(int i = 1;i <= n;i++)
	{
		int r,c;
		cin >> r >> c;
		board[r][c] = -1;
	}
	for(int i = 1;i <= 3;i++)
	{
		for(int j = 1;j <= 3;j++)
		{
			if(board[i][j] == 0)
			{
				if(n == 3)
				{
					int ed = board[fx][fy];
					board[fx][fy] = 0;
					board[i][j] = 1;
					if(check())
					{
						cout << i << " " << j << endl;
						return;
					}
					board[fx][fy] = ed;
					board[i][j] = 0;
				}
				else
				{
					board[i][j] = 1;
					if(check())
					{
						cout << i << " " << j << endl;
						return;
					}
					board[i][j] = 0;
				}
			}
		}
	}
	cout << "Columbina Hyposelenia" << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}