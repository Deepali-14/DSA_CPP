//Program of singly linked list
#include<iostream>
#include<malloc.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *start=NULL;
void init()
{
	start=NULL;
}
int size()
{
	NODE *i;
	if(start==NULL)
	return 0;
	else
	{
		int c=0;
		for(i=start; i!=NULL; i=i->next)
			c++;
		return c;
	}
}
NODE *createnode(int d)
{
	NODE *temp;
	temp=(NODE *) malloc(sizeof(NODE));
	temp->data=d;
	temp->next=NULL;
	return temp;
}
void insertf(int d)
{
	NODE *temp;
	temp=createnode(d);
	if(start==NULL)
		start=temp;
	else
	{
		temp->next=start;
		start=temp;
	}
}
void insertl(int d)
{
	NODE *temp, *i;
	temp=createnode(d);
	if(start==NULL)
		insertf(d);
	else
	{
		for(i=start; i->next!=NULL; i=i->next);
			i->next=temp;
	}
}
void insertr(int pos, int d)
{
	int l=size();
	if(start==NULL)
	{
		cout<<"\n Linked list is empty";
	}
	else if(pos<1 || pos>l+1)
	{
		cout<<"\n Wrong position entered"<<endl;
	}
	else if(pos==1)
	{
		insertf(d);
	}
	else if(pos==l)
	{
		insertl(d);
	}
	else
	{
		NODE *temp,*i;
		int j;
		temp=createnode(d);
		for(i=start,j=1; j<pos-1; j++,i=i->next);
		temp->next=i->next;
		i->next=temp;
	}
}
void insertm(int d)
{
	NODE *i;
	int l=size();
	l=l/2;
	if(start==NULL)
	{
		insertf(d);
	}
	else
	{
		NODE *temp;
		temp=createnode(d);
		int j;
		for(i=start,j=1; j<l; j++,i=i->next);
		temp->next=i->next;
		i->next=temp;
	}
}
void display()
{
	NODE *i;
	if(start==NULL)
		cout<<"\n There is no element in linked list to display"<<endl;
	else
	{
		cout<<"Linked List ->"<<endl;
		for(i=start; i!=NULL; i=i->next)
		cout<<" "<<i->data<<" ";
	}
}
int deletef()
{
	NODE *p;
	if(start==NULL)
		return -999;
	else
	{
		p=start;
		int d=p->data;
		start=p->next;
		free(p);
		return d;
	}
}
int deletel()
{
	NODE *i,*p;
	int l=size();
	if(start==NULL)
		return -999;
	else if(l==1)
	{
		deletef();
	}
	else
	{
		int j;
		for(i=start, j=1; j<(l-1); j++, i=i->next);
		p=i->next;
		int d=p->data;
		i->next=NULL;
		free(p);
		return d;
	}
}
int deletem()
{
	if(start==NULL)
		return -999;
	else if(size()==1)
	{
		deletef();
	}
	else
	{
		NODE *i,*t;
		int j;
		for(i=start, j=1; j<size()/2; j++,i=i->next);
		t=i->next;
		i->next=t->next;
		int d=t->data;
		free(t);
		return d;
	}
}
int deleter(int pos)
{
	int l=size();
	if(start==NULL)
		return -9999;
	else if(pos<1 || pos>l+1)
		return -999;
	else if(pos==1)
	{
		deletef();
	}
	else if(pos==l)
	{
		deletel();
	}
	else
	{
		NODE *i,*t;
		int j;
		for(i=start,j=1; j<pos-1 ;j++,i=i->next);
		t=i->next;
		i->next=t->next;
		int d=t->data;
		free(t);
		return d;
	}
}
void delspdata(int x)
{
	NODE *p=start,*t;
	int flag=0;
	if(start==NULL)
	{
		printf("\n Linked list is empty");
		return;
	}
	else
	{
		while(p!=NULL)
    	{
		    if(p==start)
		    {
			    if(start->data==x)
			    {
				    flag++;
				    start=start->next;
				    p=start;
			    }
			    else
			    {
				    t=p;
				    p=p->next;
			    }
		    }
		    else if(p->data==x)
		    {
			    flag++;
			    t->next=p->next;
			    p=t->next;
		    }
	    	else
	    	{
			    t=p;
			    p=p->next;
		    }
	    }
    }
	if(flag==0)
		printf("\n Element not found");
}
int main()
{
	int ch,d,loc,res;
	do
	{
		cout<<"\n 1. INITIALIZTION \n 2. INSERT FIRST \n 3. INSERT RANDOM \n 4. INSERT MIDDLE \n 5. INSERT LAST ";
		cout<<"\n 6. DELETE FIRST \n 7. DELETE RANDOM \n 8. DELETE MIDDLE \n 9. DELETE LAST \n 10. DELETE SPECIFIC DATA ";
		cout<<"\n 11. DISPLAY \n 12. SIZE \n 0.EXIT"<<endl;
		cout<<"Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				init();
				break;
			case 2:
				cout<<"\n Enter element to insert : ";
				cin>>d;
				insertf(d);
				break;
			case 3:
				cout<<"\n Enter element to insert : ";
				cin>>d;
				cout<<"\n Enter position to insert to : ";
				cin>>loc;
				insertr(loc,d);
				break;
			case 4:
				cout<<"\n Enter element to insert : ";
				cin>>d;
				insertm(d);
				break;
			case 5:
				cout<<"\n Enter element to insert : ";
				cin>>d;
				insertl(d);
				break;
			case 6:
				res=deletef();
				if(res==-999)
					cout<<"\n Linked list is empty"<<endl;
				else
					cout<<"\n Deleted node data -> "<<res<<endl;
				break;
			case 7:
				cout<<"\n Enter position to delete from : ";
				cin>>loc;
				res=deleter(loc);
				if(res==-9999)
					cout<<"\n Linked list is empty"<<endl;
				else if(res==-999)
					cout<<"\n Wrong position entered"<<endl;
				else
					cout<<"\n Deleted node data -> "<<res<<endl;
				break;
			case 8:
				res=deletem();
				if(res==-999)
					cout<<"\n Linked list is empty"<<endl;
				else
					cout<<"\n Deleted node data -> "<<res<<endl;
				break;
			case 9:
				res=deletel();
				if(res==-999)
					cout<<"\n Linked list is empty"<<endl;
				else
					cout<<"\n Deleted node data -> "<<res<<endl;
				break;
			case 10:
				cout<<"\n Enter element to be deleted : ";
				cin>>d;
				delspdata(d);
				break;
			case 11:
				display();
				break;
			case 12:
				if(size()==-999)
					cout<<"\n Size -> 0"<<endl;
				else
					cout<<"\n Size -> "<<size()<<endl;
				break;
			case 0:
				cout<<"\n We are exiting !!!!!!"<<endl;
				break;
			default:
				cout<<"\n Wrong choice entered"<<endl;
		}
		
	}while(ch!=0);
	
	return 0;
}
