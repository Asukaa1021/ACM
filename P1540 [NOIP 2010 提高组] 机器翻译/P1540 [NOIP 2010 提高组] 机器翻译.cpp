#include<bits/stdc++.h>
using namespace std;

queue<int> nc;
int cnt=0;
bool pd[1005];
bool b[1005];

int main()
{
	int len,m;
	cin>>len>>m;
	for(int i=1;i<=m;i++)
	{
		int num;
		cin>>num;
		if(pd[num] == false)
		{
			cnt++;
		}
		if(pd[num] == false)
		{
			
			if(nc.size() < len)
			{
				nc.push(num);
				pd[num] = true;
			}
			else
			{	
				pd[nc.front()] = false;
				nc.pop();
				nc.push(num);
				pd[num] = true;
			}
		}
	}
	cout<<cnt<<endl;
}