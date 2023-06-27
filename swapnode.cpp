#include<iostream>
#include<malloc.h>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node node;
node *s=NULL;
node * createnode(int x)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=x;
	temp->next=NULL;
	return temp;
}
void create(int x)
{
	node *temp,*p;
	temp=createnode(x);
	if(s==NULL)
	s=temp;
	else
	{
		for(p=s;p->next!=NULL;p=p->next);
		p->next=temp;
	}
}
void display()
{
	node *p;
	if(s==NULL)
	cout<<"\n LINKED LIST IS EMPTY"<<endl;
	else
	{
		cout<<"\n LINKED LIST : "<<endl;
	    for(p=s;p!=NULL;p=p->next)
	    	cout<<" "<<p->data;
	    cout<<endl;
	}
}
int search(int z)
{
	node *p;
	int i,flag=0;
	for(p=s,i=1; p!=NULL; i++,p=p->next)
	{
		if(p->data==z)
		{
			flag=1;
			return i;
		}
		else
		continue;
	}
	if(p==NULL && flag==0)
	return -999;
}
void swap(int i, int j)
{
	node *p,*t=NULL,*prevx,*prevy,*px,*py,*temp;
	int pos;
	
	if(j==i+1)
	{
		for(p=s,pos=1; pos<i; pos++,t=p,p=p->next);
		prevx=t;
		px=p;
		
		for(p=s,pos=1; pos<j; pos++,p=p->next);
		py=p;
		
		temp=py->next;
		py->next=px;
		px->next=temp;
		if(prevx==NULL)
		{
			s=py;
		}
		if(prevx!=NULL)
		{
			prevx->next=py;
		}
	}
	else
	{
		for(p=s,pos=1; pos<i; pos++,t=p,p=p->next);
		prevx=t;
		px=p;
		
		for(p=s,pos=1; pos<j; pos++,t=p,p=p->next);
		prevy=t;
		py=p;
		
		temp=py->next;
		py->next=px->next;
		px->next=temp;
		if(prevx==NULL)
		{
			s=py;
			prevy->next=px;
		}
		if(prevy==NULL)
		{
			s=px;
			prevx->next=py;
		}
		if(prevx!=NULL && prevy!=NULL)
		{
			prevx->next=py;
			prevy->next=px;
		}
	}
}
int main()
{
	int ch,x,y,i,j,n;
	cout<<"\n *************** Program to swap a node **************"<<endl;
	do
	{
		cout<<"\n 1. Create \n 2. Display \n 3. Swap \n 0. Exit"<<endl;
		cout<<"\n Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1: 
				cout<<"\n Enter number of elements to insert in linked list : ";
				cin>>n;
				for(int k=0; k<n; k++)
				{
					cout<<"\n Enter "<<k+1<<" element to insert : ";
					cin>>x;
					create(x);
				}
				break;
			case 2:
				display();
				break;
			case 3:
				cout<<"\n Enter element to swap : ";
				cin>>x;
				i=search(x);
				cout<<i<<endl;
				cout<<"\n Enter element to swap with : ";
				cin>>y;
				j=search(y);
				cout<<j;
				if(i==-999 || j==-999)
					cout<<"\n Swap operation cannot be performed"<<endl;
				else
					swap(i,j);
				break;
			case 0:
				cout<<"\n We are exiting :)"<<endl;
				break;
			default:
				cout<<"\n Wrong choice entered :("<<endl;
		}	
	}while(ch!=0);
	
	return 0;
}
