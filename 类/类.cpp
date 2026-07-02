#include<bits/stdc++.h>
using namespace std;

class Student
{
	private:
			int num;
			int score;
	public:
			void setdata()
			{
				cin>>num>>score;
			}
						
			void outdata()
			{
				cout<<num<<" "<<score<<endl;
			}
				
};

int main()
{
	Student s1,s2;
	s1.setdata();
	s2.setdata();
	s1.outdata();
	s2.outdata();
	
	
	return 0;
}
