#include<iostream>
#include<malloc.h>
using namespace std;

struct CNODE 
{
	int data;
	struct CNODE *next;
};
typedef struct CNODE cnode;

cnode * init(cnode *s)
{
	s=NULL;
	return s;
}
void display(cnode *s)
{
	cnode *p;
	if(s==NULL)
	{
		cout<<"\n Circular linked list is empty"<<endl;
	}
	else
	{
		cout<<"\n Circular linked list -> "<<endl;
		for(p=s; p->next!=s; p=p->next)
		cout<<" "<<p->data<<"->";
		cout<<" "<<p->data;
		cout<<endl;
	}
}
int size(cnode *s)
{
	if(s==NULL)
		return 0;
	else
	{
		cnode *p;
		int count;
		for(p=s, count=1; p->next!=s; count++,p=p->next);
			return count;
	}
}
cnode * reversecll(cnode *s)
{
	if(s==NULL || s->next==NULL)
		return s;
	else
	{
		cnode *p=NULL, *c=s, *n=NULL, *temp;
		for(c=s; c->next!=s; c=c->next);
		temp=c;
		n=s->next;
		c=s;
		while(n!=s)
		{
			if(c==s)
			{
				c->next=temp;
				p=c;
				c=n;
			}
			else
			{
				n=n->next;
				c->next=p;
				p=c;
				c=n;
			}
		}
		s=p;
		return s;
	}
}
cnode * createnode(cnode *s, int x)
{
	cnode *temp;
	temp=(cnode *)malloc(sizeof(cnode));
	temp->data=x;
	return temp;
}
cnode * insertf(cnode *s, int x)
{
	cnode *temp;
	temp=createnode(s,x);
	if(s==NULL)
	{
		s=temp;
		temp->next=s;
		return s;
	}
	else
	{
		cnode *p;
		for(p=s; p->next!=s; p=p->next);
		p->next=temp;
		temp->next=s;
		s=temp;
		return s;
	}
}
cnode * insertl(cnode *s, int x)
{
	cnode *temp,*p;
	temp=createnode(s,x);
	if(s==NULL)
	{
		s=temp;
		temp->next=s;
		return s;
	}
	else
	{
		for(p=s; p->next!=s; p=p->next);
		p->next=temp;
		temp->next=s;
		return s;
	}
}
cnode * insertr(cnode *s, int pos, int x)
{
	int l=size(s);
	if(pos<1 || pos>l+1)
	{
		cout<<"\n Wrong position to insert :("<<endl;
		return s;
	}
	else if(pos==1)
	{
		s=insertf(s,x);
		return s;	
	}
	else if(pos==l+1)
	{
		s=insertl(s,x);
		return s;
	}
	else
	{
		cnode *temp,*p;
		int i;
		temp=createnode(s,x);
		for(p=s, i=1; i<pos-1; i++,p=p->next);
		temp->next=p->next;
		p->next=temp;
		return s;
	}
}
cnode *deletef(cnode *s)
{
	if(s==NULL)
	{
		cout<<"\n Circular linked list is empty"<<endl;
		return s;
	}
	else if(s->next==s)
	{
		cnode *p=s;
		cout<<"\n Deleted element : "<<p->data<<endl;
		s=NULL;
		free(p);
		return s;
	}
	else
	{
		cnode *temp;
		temp=s;
		cnode *p;
		for(p=s; p->next!=s; p=p->next);
		s=temp->next;
		p->next=s;
		cout<<"\n Deleted element : "<<temp->data<<endl;
		free(temp);
		return s;
	}
	return s;
}
cnode * deletel(cnode *s)
{
	if(s==NULL)
	{
		cout<<"\n Circular linked list is empty"<<endl;
		return s;
	}
	else if(s->next==s)
	{
		cnode *p=s;
		cout<<"\n Deleted element : "<<p->data<<endl;
		s=NULL;
		free(p);
		return s;
	}
	else
	{
		cnode *p,*temp;
		for(p=s; p->next!=s; temp=p,p=p->next);
		temp->next=s;
		cout<<"\n Deleted element : "<<p->data<<endl;
		free(p);
		return s;
	}
}
cnode * deleter(cnode *s, int pos)
{
	int l=size(s);
	if(start==NULL)
	{
		printf("\n Circular linked list is empty");
		return s;
	}
	if(pos<1 || pos>l)
	{
		cout<<"\n Wrong position to delete"<<endl;
		return s;
	}
	else if(pos==1)
	{
		s=deletef(s);
		return s;
	}
	else if(pos==l)
	{
		s=deletel(s);
		return s;
	}
	else
	{
		cnode *p,*temp;
		int i;
		for(p=s,i=1; i<pos-1; i++, p=p->next);
		temp=p->next;
		p->next=temp->next;
		cout<<"\n Deleted element : "<<temp->data<<endl;
		free(temp);
		return s;
	}
}
int main()
{
	cnode *s=NULL;
	int ch,x,pos;
	cout<<"\n -----------------------------------CIRCULAR LINKED LIST-------------------------------"<<endl;
	do
	{
		cout<<"\n 1. Initialization \n 2. Insert first \n 3. Insert last \n 4. Delete first \n 5. Delete last";
		cout<<"\n 6. Delete random \n 7. Insert random \n 8. Size \n 9. Display \n 10. Reverse \n 0. Exit"<<endl;
		cout<<"\n Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				s=init(s);
				break;
			case 2:
				cout<<"\n Enter element to insert : ";
				cin>>x;
				s=insertf(s,x);
				break;
			case 3:
				cout<<"\n Enter element to insert : ";
				cin>>x;
				s=insertl(s,x);
				break;
			case 4:
				s=deletef(s);
				break;
			case 5:
				s=deletel(s);
				break;
			case 6:
				cout<<"\n Enter position to delete from : ";
				cin>>pos;
				s=deleter(s,pos);
				break;
			case 7:
				cout<<"\n Enter element to insert : ";
				cin>>x;
				cout<<"\n Enter position to insert to : ";
				cin>>pos;
				s=insertr(s,pos,x);
				break;
			case 8:
				cout<<"\n Size -> "<<size(s)<<endl;
				break;
			case 9:
				display(s);
				break;
			case 10:
				s=reversecll(s);
				break;
			case 0:
				cout<<"\n We are exiting ;)"<<endl;
				break;
			default:
				cout<<"\n Wrong choice entered :("<<endl;
		}
	}while(ch!=0);
	return 0;
}
