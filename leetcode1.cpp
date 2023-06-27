#include<iostream>
#include<malloc.h>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node node;
node *start=NULL;
void init()
{
	start=NULL;
}
node* createnode(int x)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=x;
	temp->next=NULL;
	return temp;
}
void insert(int x)
{
	node *temp, *p;
	temp=createnode(x);
	if(start==NULL)
		start=temp;
	else
	{
		for(p=start; p->next!=NULL; p=p->next);
			p->next=temp;
	}
}
void display()
{
	node *p;
	if(start==NULL)
	{
		cout<<"\n Linked List is empty"<<endl;
		return;
	}
	else
	{
		cout<<"\n Linked list : ";
		for(p=start; p->next!=NULL; p=p->next)
			cout<<" "<<p->data<<" -> ";
		cout<<p->data;
		cout<<endl;
	}
}
void reversesll()
{
	node *pn=NULL, *nn=start, *cn=start;
	if(start==NULL)
	{
		cout<<"\n There is no element to reverse"<<endl;
		return;
	}
	
	else if(start->next==NULL)
	{
		cout<<"\n There is no reverse possible as only one element is there"<<endl;
		return;
	}
		
	else
	{
		while(nn!=NULL)
		{
			nn=nn->next;
			cn->next=pn;
			pn=cn;
			cn=nn;
		}
		start=pn;
	}
}
int main()
{
	int n;
	cout<<"\n Enter no. of elements you want to insert in singly linked list : ";
	cin>>n;
	int x;
	for(int i=0; i<n; i++)
	{
		cout<<"\n Enter "<<i+1<<" element : ";
		cin>>x;
		insert(x);
	}
	display();
	reversesll();
	display();
	return 0;
}
