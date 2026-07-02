#include<bits/stdc++.h>
using namespace std;
long long ans = 0;

int main()
{
    string s;
    cin >> s;
    int len = s.size();
    s = " " + s;
    for(int i = 1;i <= len;i++)
    {
    	for(int j = 1;j < i;j++)
    	{
    		if(s[j] > s[i])
    		{
    			ans++;
    			int ii = i + 1,jj = j - 1;
    			while(1 <= jj && ii <= len && s[ii] == s[jj])
    			{
    				ans++;
    				ii++,jj--;
				}
			}
		}
	}
	cout << ans << endl;
}

