#include<bits/stdc++.h>
using namespace std;


int main()
{
	int num;
	cin >> num;
	int n,q;
	cin >> n >> q;
	string s1 = "freopen(\"",s2 = ".in\",\"r\",stdin);",s3 = ".out\",\"w\",stdout);";
	vector<string> title(q + 1);
	
	for(int i = 1;i <= q;i++) cin >> title[i];
	string emptyLine;
	getline(cin, emptyLine);
	while(n--)
	{
		getline(cin, emptyLine);
		int t = 1;
		for(int i = 1;i <= q;i++)
		{
			string se1,se2;
			cin >> se1 >> se2;
			string sen1 = s1 + title[i] + s2;
			string sen2 = s1 + title[i] + s3;
			int len1 = se1.size();
			int len2 = se2.size();
			string begin1 = se1.substr(0,min(len1,10));
			string end1 = se1.substr(max(0,len1 - 2));
			string begin2 = se2.substr(0,min(len2,10));
			string end2 = se2.substr(max(0,len2 - 2));
			if(t != 3)
				if((begin1 == "//freopen(" && end1 == ");" )|| (begin2 == "//freopen(" && end2 == ");") ) t = 3;
				else if(se1 != sen1 || se2 != sen2) t = 2;
		}
		if(t == 1) cout << "PION2202 RP++." << endl;
		else if(t == 3) cout << "Wrong file operation takes you to your ancestors along with your 3 years' efforts on OI." << endl;
		else cout << "Good luck and have fun." << endl;
	}
}