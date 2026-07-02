#include<bits/stdc++.h>
using namespace std;

int n,q,k,len;
struct node
{
	int num,tim;
	node *prev = nullptr,*next = nullptr;
};

node *head = new node,*tail = new node;
unordered_map<int,node*> mp;

int main()
{
	cin >> n >> q >> k;
	head -> next = tail;
	tail -> prev = head;
	while(q--)
	{
		int ddel = -1;
		int book;
		cin >> book;
		if(mp.count(book))
		{
			node *pos = mp[book];
			pos -> next -> prev = pos -> prev;
			pos -> prev -> next = pos -> next;
			
			pos -> next = tail;
			pos -> prev = tail -> prev;
			tail -> prev -> next = pos;
			tail -> prev = pos;
		}
		else
		{
			if(len < k)
			{
				len++;
				node *temp = new node;
				temp -> num = book;
				mp[book] = temp;
				temp -> next = tail;
				temp -> prev = tail -> prev;
				tail -> prev -> next = temp;
				tail -> prev = temp;
			}
			else
			{
				node *del = head -> next;
				mp.erase(del -> num);
				ddel = del -> num;
				del -> next -> prev = del -> prev;
				del -> prev -> next = del -> next;
				delete del;
				node *temp = new node;
				temp -> num = book;
				temp -> next = tail;
				temp -> prev = tail -> prev;
				tail -> prev -> next = temp;
				tail -> prev = temp;
				mp[book] = temp;
			}
		}
		cout << ddel << "\n";
	}
}