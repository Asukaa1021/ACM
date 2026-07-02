#include<bits/stdc++.h>
using namespace std;

string sen;

int main()
{
	getline(cin,sen);
	int count=0;
	for(int i=0;i<sen.size();i++)
	{
		if(sen[i]==' '||sen[i]=='a'||sen[i]=='d'||sen[i]=='g'||sen[i]=='j'||sen[i]=='m'||sen[i]=='p'||sen[i]=='t'||sen[i]=='w') count++;
	
		if(sen[i]=='b'||sen[i]=='e'||sen[i]=='h'||sen[i]=='k'||sen[i]=='n'||sen[i]=='q'||sen[i]=='u'||sen[i]=='x') count+=2;
		
		if(sen[i]=='c'||sen[i]=='i'||sen[i]=='l'||sen[i]=='o'||sen[i]=='r'||sen[i]=='v'||sen[i]=='y'||sen[i]=='f') count+=3;
		
		if(sen[i]=='s'||sen[i]=='z') count+=4;
	}
	cout<<count<<endl;
	return 0;
}