#include<iostream>
#include<malloc.h>
using namespace std;
struct DNODE
{
	int data;
	struct DNODE *prev;
	struct DNODE *next;
};
typedef struct DNODE dnode;
dnode * init(dnode *s)
{
	s=NULL;
	return s;
}
dnode * createnode(dnode *s, int x)
{
	dnode *temp;
	temp=(dnode *)malloc(sizeof(dnode));
	temp->data=x;
	temp->prev=NULL;
	temp->next=NULL;
	return temp;
}
dnode * insertf(dnode *s, int x)
{
	dnode *temp;
	temp=createnode(s,x);
	
	if(s==NULL)
	{
		s=temp;
		return s;
	}
	else
	{
		temp->next=s;
		s->prev=temp;
		s=temp;
		return s;
	}
}
dnode * insertl(dnode *s,int x)
{
	dnode *p, *temp;
	temp=createnode(s,x);
	if(s==NULL)
		s=temp;
		
	else
	{
		for(p=s; p->next!=NULL; p=p->next);
		p->next=temp;
		temp->prev=p;
	}
	return s;
}
void forward_display(dnode *s)
{
	if(s==NULL)
	{
		cout<<"\n Doubly linked list is empty"<<endl;
	}
	else
	{
		cout<<"\n Doubly linked list : "<<endl;
		dnode *p;
		for(p=s; p!=NULL; p=p->next)
			cout<<" "<<p->data;
		cout<<endl;
	}
}
void backward_display(dnode *s)
{
	if(s==NULL)
	{
		cout<<"\n Doubly linked list is empty"<<endl;
	}
	else
	{
		cout<<"\n Doubly linked list : "<<endl;
		dnode *p;
		for(p=s; p->next!=NULL; p=p->next);
		for(; p!=NULL; p=p->prev)
			cout<<" "<<p->data;
		cout<<endl;
	}
}
dnode * reverse_dll(dnode *s)
{
	dnode *cn=s, *nn;
	while(nn!=NULL)
	{
		s=cn;
		nn=cn->next;
		cn->next=cn->prev;
		cn->prev=nn;
		cn=nn;
	}
	return s;
}
dnode * deletef(dnode *s)
{
	if(s==NULL)
	{
		cout<<"\n Doubly linked list is empty"<<endl;
		return s;
	}
	else if(s->next==NULL)
	{
		cout<<"\n Deleted element -> "<<s->data<<endl;
		free(s);
		s=NULL;
		return s;
	}
	else
	{
		dnode *p;
		p=s;
		s=s->next;
		s->prev=NULL;
		cout<<"\n Deleted element -> "<<p->data<<endl;
		free(p);
		return s;
	}
}
dnode * deletel(dnode *s)
{
	if(s==NULL)
	{
		cout<<"\n Doubly Linked list is empty"<<endl;
		return s;
	}
	else if(s->next==NULL)
	{
		s=deletef(s);
		return s;
	}
	else
	{
		dnode *p;
		for(p=s; p->next!=NULL; p=p->next);
		cout<<"\n Deleted element -> "<<p->data<<endl;
		(p->prev)->next=NULL;
		free(p);
		return s;
	}
}
int size(dnode *s)
{
	if(s==NULL)
	{
		return 0;
	}
	else
	{
		dnode *p;
		int i;
		for(i=1, p=s; p->next!=NULL; i++, p=p->next);
		return i;
	}
}
dnode * insertr(dnode *s, int pos, int x)
{
	int l=size(s);
	if(pos==1)
	{
		s=insertf(s,x);
		return s;
	}
	else if(pos<1 || pos>(l+1))
	{
		cout<<"\n Wrong position given"<<endl;
		return s;
	}	
	else if(pos==l+1)
	{
		s=insertl(s,x);
		return s;
	}
	else
	{
		dnode *p,*t,*temp;
		int i;
		temp=createnode(s,x);
		for(p=s,i=1; i<pos; i++,p=p->next);
		t=p->prev;
		t->next=temp;
		temp->prev=t;
		temp->next=p;
		p->prev=temp;
		return s;
	}
}
dnode * deleter(dnode *s, int pos)
{
	int l=size(s);
	if(pos==1)
	{
		s=deletef(s);
		return s;
	}
	else if(pos<1 || pos>l)
	{
		cout<<"\n Wrong position given"<<endl;
		return s;
	}	
	else if(pos==l)
	{
		s=deletel(s);
		return s;
	}
	else
	{
		dnode *p,*t,*temp;
		int i;
		for(p=s,i=1; i<pos; i++,p=p->next);
		t=p->prev;
		temp=p->next;
		t->next=temp;
		temp->prev=t;
		cout<<"\n Deleted element -> "<<p->data<<endl;
		free(p);
		return s;
	}
}
int main()
{
	dnode *s=NULL;
	int ch,x,pos;
	do
	{
		cout<<"\n 1. INITIALIZATION \n 2. INSERT FIRST \n 3. INSERT LAST \n 4. INSERT RANDOM";
		cout<<"\n 5. DELETE FIRST \n 6. DELETE LAST \n 7. DELETE RANDOM \n 8. FORWARD DISPLAY \n 9. BACKWARD DISPLAY";
		cout<<"\n 10. REVERSE \n 11. SIZE \n 0. EXIT";
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
				cout<<"\n Enter element to insert : ";
				cin>>x;
				cout<<"\n Enter position to insert to : ";
				cin>>pos;
				s=insertr(s,x,pos);
				break;
			case 5:
				s=deletef(s);
				break;
			case 6:
				s=deletel(s);
				break;
			case 7:
				cout<<"\n Enter position to delete from : ";
				cin>>pos;
				s=deleter(s,pos);
				break;
			case 8:
				forward_display(s);
				break;
			case 9:
				backward_display(s);
				break;
			case 10:
				s=reverse_dll(s);
				break;
			case 11:
				cout<<"\n Size -> "<<size(s)<<endl;
				break;
			case 0:
				cout<<"\n We are Exiting !!!"<<endl;
				break;
			default:
				cout<<"\n Wrong choice entered! Please try again :("<<endl;
		}
	}while(ch!=0);
	
	return 0;
}
