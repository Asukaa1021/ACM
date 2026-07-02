#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int num;
	Node* prev;
	Node* next;
};
Node* head = nullptr;
Node* last = nullptr;
void insertNum(int num)
{
	Node* temp = new Node;
	Node* p;
	temp->num = num;
	temp->prev = nullptr;
	temp->next = nullptr;
	if(head == nullptr)
	{
		head = temp;
		last = temp;
		return;
	}
	p=head;
	while(p!= nullptr && p->num < temp->num)
	{
		p=p->next;
	}
	if(p == nullptr)//如果p为空  p插入链表尾部
	{
		temp->prev=last;
		last->next=temp;
		last=temp;
	}
	else if(p == head)//如果head->num > num 更新头节点
	{
		temp->next=p;
		p->prev = temp;
		head = temp;
	}
	else
	{
		temp->next=p;
		temp->prev=p->prev;
		p->prev->next=temp;
		p->prev=temp;
	}//插入链表中
}

void searchRate(int num)
{
	Node* p=head;
	int cnt=0;
	while(p!=nullptr && p->num < num)
	{
		p=p->next;
		cnt++;
	}
	cout<<cnt+1<<endl;
}

void searchNum(int num)
{
	Node* p = head;
	for(int i=2;i<=num;i++)	p=p->next;
	cout<<p->num<<endl;
}

void searchPrev(int num)
{
	Node* p = last;
	while(p!=nullptr && p->num >= num)	p=p->prev;
	if(p==nullptr) cout<<"-2147483647"<<endl;
	else cout<<p->num<<endl;
}

void searchNext(int num)
{
	Node* p= head;
	while(p!=nullptr && p->num <= num)	p=p->next;
	if(p==nullptr) cout<<"2147483647"<<endl;
	else cout<<p->num<<endl;
}

int main()
{
	//freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int q;
	cin>>q;
	while(q--)
	{
		int op,num;
		cin>>op>>num;
		if(op==1) searchRate(num);
		if(op==2) searchNum(num);
		if(op==3) searchPrev(num);
		if(op==4) searchNext(num);
		if(op==5) insertNum(num);
	}
}