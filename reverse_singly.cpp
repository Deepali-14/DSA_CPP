#include<iostream>
#include<malloc.h>
using namespace std;
struct node
{
	int data;
	struct node *info;
};
typedef struct node Node;
Node * createnode(int x)
{
	Node *temp;
	temp=(Node *)malloc(sizeof(Node));
	temp->data=x;
	temp->info=NULL;
	return temp;
}
Node *create(Node *s)
{
	Node *temp, *p;
	int n;
	cout<<"\n Enter total number of elements you want to insert : ";
	cin>>n;
	int x;
	for(int i=0; i<n ; i++)
	{
		cout<<"\n Enter element "<<i+1<<" : "<<endl;
		cin>>x;
		temp=createnode(x);
		if(s==NULL)
		s=temp;
		else
		{
			for(p=s; p->info!=NULL; p=p->info);
			p->info=temp;
		}
	}
	return s;
}
void display(Node *s)
{
	if(s==NULL)
		cout<<"\n There is no element to display"<<endl;
	else
	{
		Node *p;
		cout<<"\n Linked list : "<<endl;
		for(p=s; p!=NULL; p=p->info)
			cout<<p->data<<" ";
		cout<<endl;
	}
}
Node * revsll(Node *s)
{
	Node *pn=NULL, *cn=s, *nn=s;
	if(s==NULL || s->info==NULL)
		return s;
	else
	{
		while(nn!=NULL)
		{
			nn=nn->info;
			cn->info=pn;
			pn=cn;
			cn=nn;
		}
		s=pn;
		return s;
	}
	
}
int main()
{
	Node *s=NULL;
	cout<<"\n Singly linked list : "<<endl;
	s=create(s);
	display(s);
	cout<<"\n Reverse Singly linked list : "<<endl;
	s=revsll(s);
	display(s);
	return 0;
}
