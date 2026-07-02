#include<bits/stdc++.h>
using namespace std;

struct node
{
	int num;
	node* next;
};

node* makelist(int arr[],int n)
{
	node* head=new node;
	node* p=head;
	
	for(int i=1;i<=n;i++)
	{
		node* temp=new node;
		p->num=arr[i-1];
		p->next=temp;
		p=p->next;
	}
	p->num=arr[n];
	p->next=head->next;//循环链表
	return head;//返回头指针
}

void Printlist(node* head,int k)
{
	node* p=head;
	node* prev=NULL;
	
	while(p!=p->next)
	{	
		for(int i=1;i<=k;i++)
		{
			prev=p;//记录前一个地址
			p=p->next;//向后移动一个单位
		}
		cout<<p->num<<" ";
		prev->next=p->next;//删除元素
	}
}


int main()
{
	int n,k;
	int arr[105];
	cin>>n>>k;
	for(int i=1;i<=n;i++) arr[i]=i;
	node* head=makelist(arr,n);
	Printlist(head,k);
}