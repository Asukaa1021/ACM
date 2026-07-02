#include<bits/stdc++.h>
using namespace std;
stack<int> stk;
int pushed[100005];
int poped[100005];
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		bool b=true;
		cin>>n;
		int j=1;
		for(int i=1;i<=n;i++) cin>>pushed[i];
		for(int i=1;i<=n;i++) cin>>poped[i];
		
		for(int i=1;i<=n;i++)
		{
			if(!stk.empty() && stk.top()==poped[i])//不为空且匹配
			{
				stk.pop();
				continue;
			}
			else
			{
				while((stk.empty() || poped[i]!=stk.top()) && j<=n)
				{
					stk.push(pushed[j]);
					j++;
				}
				if(stk.top()==pushed[j-1])
				{
					stk.pop();
					continue;
				}
				else if(j==n+1)//找出去了
				{
					cout<<"No"<<endl;
					b=false;
					break;
				}
			}
		}
		if(b==true)
		{
			cout<<"Yes"<<endl;
		}
	}
}