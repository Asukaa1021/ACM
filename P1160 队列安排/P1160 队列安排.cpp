#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int num;
	Node* prev;
	Node* next;	
};

Node* head;
Node* last;
Node* node[100005];
bool notInList[100005];

Node* createNode(int i)
{
	Node* newNode=new Node;
	newNode->num = i;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	return newNode;
}

void leftInsertNode(int y,int i)
{
	Node* NodeY=node[y];
	Node* NodeI=node[i];
	
	NodeI->next = NodeY;
	NodeI->prev = NodeY->prev;
	
	if(NodeY->prev != nullptr)
	{
		NodeY -> prev -> next = NodeI;
	}
	else 
	{
		head=NodeI;
	}
	 NodeY->prev=NodeI;
	
	
}

void rightInsertNode(int y,int i)
{
	Node* NodeY=node[y];
	Node* NodeI=node[i];
	
	NodeI->next = NodeY -> next;
	NodeI->prev = NodeY;
	
	if(NodeY->next != nullptr)
	{
		NodeY->next->prev=NodeI;
	}
	else
	{
		last=NodeI;
	}
	NodeY->next=NodeI;
}
/*
bool isInList(int x)
{
	Node* p=head;
	while(p!=nullptr)
	{
		if(p->num==x)
		{
			return true;
		}
		p=p->next;
	}
	return false;
}*/


void deleteNode(int i)
{
	if(notInList[i]==1) return;
	notInList[i]=1;
	Node* NodeI=node[i];
	
	if(NodeI==head)
	{
		head=NodeI->next;
	}
	if(NodeI==last)
	{
		last=NodeI->prev;
	}
	if(NodeI->next!=nullptr)
	{
		NodeI->next->prev=NodeI->prev;
	}
	if(NodeI->prev!=nullptr)
	{
		NodeI->prev->next=NodeI->next;
	}
	
	NodeI->prev=nullptr;
	NodeI->next=nullptr;
}

void printList(void)
{
	Node* p=head;
	while(p!=nullptr)
	{
		cout<<p->num<<" ";
		p=p->next;
	}
}


void deleteList(void)
{
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		deleteNode(x);
	}
}
void createList(void)
{
	int n;
	cin>>n;
	node[1]=createNode(1);
	head=node[1];
	last=node[1];
	for(int i=2;i<=n;i++)
	{
		node[i]=createNode(i);
		int y,op;
		cin>>y>>op;
		if(op==0) leftInsertNode(y,i);
		else rightInsertNode(y,i);
	}
}

int main()
{
	createList();
	deleteList();
	printList();
}