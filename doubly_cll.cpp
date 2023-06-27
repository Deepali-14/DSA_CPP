#include<iostream>
#include<malloc.h>
using namespace std;
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
typedef struct node dcnode;
dcnode * init(dcnode *s)
{
	s=NULL;
	return s;
}
dcnode * createnode(dcnode *s, int x)
{
	dcnode *temp;
	temp=(dcnode *)malloc(sizeof(dcnode));
	temp->data=x;
	return temp;
}
int size(dcnode *s)
{
	dcnode *p;
	int i;
	if(s==NULL)
		return 0;
	for(i=1, p=s; p->next!=s; i++, p=p->next);
		return i;
}
void fdisplay(dcnode *s)
{
	if(s==NULL)
		cout<<"\n Doubly circular linked list is empty"<<endl;
	else
	{
		cout<<"\n Doubly circular linked list using forward display : "<<endl;
		dcnode *p;
		for(p=s; p->next!=s; p=p->next)
			cout<<" "<<p->data<<" ";
		cout<<" "<<p->data;
		cout<<endl;	
	}
}
void bdisplay(dcnode *s)
{
	if(s==NULL)
		cout<<"\n Doubly circular linked list is empty"<<endl;
	else
	{
		cout<<"\n Doubly circular linked list using backward display : "<<endl;
		dcnode *p,*t;
		for(p=s; p->next!=s; p=p->next);
		{
			t=p;
			for(;p->prev!=t;p=p->prev)
				cout<<" "<<p->data<<" ";
			cout<<" "<<p->data;
			cout<<endl;	
		}
	}
}
dcnode * insertf(dcnode *s, int x)
{
	dcnode *temp,*p;
	temp=createnode(s,x);
	if(s==NULL)
	{
		s=temp;
		temp->prev=s;
		temp->next=s;
		return s;
	}
	else
	{
		for(p=s; p->next!=s; p=p->next);
			p->next=temp;
		temp->next=s;
		temp->prev=p;
		s->prev=temp;
		s=temp;
		return s;
	}
}
dcnode * insertl(dcnode *s, int x)
{
	dcnode *temp,*p;
	temp=createnode(s,x);
	if(s==NULL)
	{
		s=temp;
		temp->prev=s;
		temp->next=s;
		return s;
	}
	else
	{
		for(p=s; p->next!=s; p=p->next);
		temp->next=s;
		temp->prev=p;
		p->next=temp;
		s->prev=temp;
		return s;
	}
}
dcnode * deletef(dcnode *s)
{
	if(s==NULL)
	{
		cout<<"\n Doubly circular linked list is empty"<<endl;
		return s;
	}
	else if(s->next==s)
	{
		dcnode *p=s;
		cout<<"\n Deleted element : "<<p->data<<endl;
		s=NULL;
		free(p);
		return s;
	}
	else
	{
		dcnode *p=s,*t;
		for(p=s; p->next!=s; p=p->next);
		p->next=s->next;
		s->next->prev=p;
		cout<<"\n Deleted element : "<<s->data<<endl;
		free(s);
		s=p->next;
		return s;
	}
}
dcnode * insertr(dcnode *s,int x, int pos)
{
	int l=size(s);
	if(pos<1 || pos>l+1)
	{
		cout<<"\n Wrong position to insert"<<endl;
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
		dcnode *p,*t,*temp;
		temp=createnode(s,x);
		int i;
		for(i=1,p=s; i<pos; i++,t=p,p=p->next);
		t->next=temp;
		p->prev=temp;
		temp->next=p;
		temp->prev=t;
		return s;
	}
}
dcnode * deletel(dcnode *s)
{
	if(s==NULL)
	{
		cout<<"\n Doubly circular linked list is empty"<<endl;
		return s;
	}
	else if(s->next==s)
	{
		dcnode *p=s;
		cout<<"\n Deleted element : "<<p->data<<endl;
		free(p);
		s=NULL;
		return s;
	}
	else
	{
		dcnode *p=s,*t;
		for(p=s; p->next!=s; t=p,p=p->next);
		t->next=s;
		cout<<"\n Deleted element : "<<p->data<<endl;
		free(p);
		s->prev=t;
	}
}
dcnode * deleter(dcnode *s, int pos)
{
	int l=size(s);
	if(s==NULL)
	{
		cout<<"\n Doubly circular linked list is empty"<<endl;
		return s;
	}
	else if(pos<1 || pos>l)
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
		dcnode *p,*t;
		int i;
		for(p=s,i=1; i<pos; i++,t=p,p=p->next);
		t->next=p->next;
		p->next->prev=t;
		cout<<"\n Deleted element : "<<p->data<<endl;
		free(p);
		return s;
	}
}
int main()
{
	cout<<"\n *********************************** DOUBLY CIRCULAR LINKED LIST *********************************************"<<endl;
    dcnode *s=NULL;
	int ch,a,p;
	do
	{
		cout<<"\n1. Initialization \n2. Insert first \n3. Insert random \n4. Insert last \n5. Display";
		cout<<"\n6. Delete first \n7. Delete random \n8. Delete last \n9. Size \n0. Exit"<<endl;
		cout<<"\n Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			     s=init(s); 
			     break;
			case 2: 
		    	 cout<<"\n Enter element to insert : ";
			     cin>>a;
		    	 s=insertf(s,a);
			     break;	
			case 3: 
			     cout<<"\n Enter element to insert : ";
			     cin>>a;
			     cout<<"\n Enter position to insert to : ";
			     cin>>p;
		    	 s=insertr(s,a,p);
			     break; 
			case 4: 
			     cout<<"\n Enter element to insert : ";
			     cin>>a;
		    	 s=insertl(s,a);
			     break;
			case 5: 
			     cout<<"\n 1. Forward display \n 2. Backward display"<<endl;
			     cout<<"\n Enter your choice : ";
			     cin>>ch;
			     switch(ch)
			     {
			     	case 1:
			     		fdisplay(s);
			     		break;
			     	case 2: 
			     	    bdisplay(s);
			     	    break;
			     	default:
			     		printf("\n Wrong choice");
				 }
			     break;
			case 6: 
			     s=deletef(s);
			     break;
			case 7: 
			     cout<<"\n Enter position to delete : ";
			     cin>>p;
			     s=deleter(s,p);
			     break;
			case 8: 
			     s=deletel(s);
			     break;
			case 9: 
			     cout<<"\n Size of doubly circular linked list : "<<size(s)<<endl;
			     break;
			case 10:
			     cout<<"\n Exiting :)"<<endl; 
			     break;    
			default:
			     cout<<"\n Wrong choice entered :("<<endl;
		}
	}while(ch!=0);
	return 0;
}

