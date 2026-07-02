#include<bits/stdc++.h>
using namespace std;

string f(string pre,string mid)
{
	if(pre.empty()) return "";
	char root=pre[0];
	pre.erase(pre.begin());
	int p=mid.find(root);
	string preLeft=pre.substr(0,p);
	string preRight=pre.substr(p,pre.size()-p);
	string midLeft=mid.substr(0,p);
	string midRight=mid.substr(p+1,mid.size()-p+1);
	return f(preLeft,midLeft)+f(preRight,midRight)+root;
}

int main()
{
	string mid,pre;
	cin>>mid>>pre;
	string s=f(pre,mid);
	cout<<s<<endl;	
}