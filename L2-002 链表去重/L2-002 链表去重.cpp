#include<bits/stdc++.h>
using namespace std;

struct node
{
	string st,ed;
	int k;
	node(string b,string c,int a):st(b),ed(c),k(a){};
};
unordered_map<string,node*> mp;
unordered_map<int,bool> vis;
vector<node*> ans,ans1;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	string begi;
	int n;
	cin >> begi >> n;
	for(int i = 1;i <= n;i++)
	{
		string s,d;
		int k;
		cin >> s >> k >> d;
		node *Node = new node(s,d,k);
		mp[s] = Node;
	}
	node *p = mp[begi];
	while(p != nullptr)
	{
		if(vis.count(abs(p -> k))) ans.push_back(p);
		else
		{
			vis[abs(p -> k)] = true;
			ans1.push_back(p);
		}
		if(mp.count(p -> ed))
			p = mp[p -> ed];
		else p = nullptr;
	}
	for(int i = 0;i < ans1.size();i++)
	{
		if(i == 0) cout << ans1[i] -> st << ' ' << ans1[i] -> k << ' ';
		else cout << ans1[i] -> st << endl << ans1[i] -> st << ' ' << ans1[i] -> k << ' ';
		if(i == ans1.size() - 1) cout << "-1" << endl;
	//	cout << endl << i << endl;
	}
//	cout << ans1[0] -> k << endl;
	for(int i = 0;i < ans.size();i++)
	{
		if(i == 0) cout << ans[i] -> st << ' ' << ans[i] -> k << ' ';
		else cout << ans[i] -> st << endl << ans[i] -> st << ' ' << ans[i] -> k << ' ';
		if(i == ans.size() - 1) cout << "-1" << endl;
	}
}