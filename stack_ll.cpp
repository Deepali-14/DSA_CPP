#include<iostream>
#include<malloc.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
typedef struct node stack;
stack *top=NULL;
void init()
{
	top=NULL;
}
stack * createnode(int x)
{
	stack *temp;
	temp=(stack *)malloc(sizeof(stack));
	temp->data=x;
	temp->next=NULL;
	return temp;
}
int size()
{
	stack *p;
	int i;
	if(top==NULL)
		return 0;
	for(p=top,i=1; p->next!=NULL; i++,p=p->next);
		return i;
}
void display()
{
	stack *p;
	if(top==NULL)
		cout<<"\n No element to display as stack is empty"<<endl;
	else
	{
		cout<<"\n Stack using linked list : "<<endl;
		for(p=top; p!=NULL; p=p->next)
			cout<<" "<<p->data;
		cout<<endl;
	}	
}
int underflow()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}
int peek()
{
	if(top==NULL)
		return -999;
	else
		return top->data;
}
void push(int x)
{
	stack *temp;
	temp=createnode(x);
	if(top==NULL)
		top=temp;
	else
	{
		temp->next=top;
		top=temp;
	}
}
int pop()
{
	if(top==NULL)
		return -999;
	else
	{
		stack *p;
		int r;
		p=top;
		r=p->data;
		top=p->next;
		free(p);
		return r;
	}
}
int main()
{
	cout<<"\n ******************* Stack using linked list ******************"<<endl;
	int ch,x,r;
	do
	{
		cout<<"\n 1. Initialization \n 2. Push \n 3. Pop \n 4. Underflow \n 5. Display \n 6. Size \n 7. Peek \n 0. Exit"<<endl;
		cout<<"\n Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n Stack initialized"<<endl;
				init();
				break;
			case 2:
				cout<<"\n Enter element to push in stack : ";
				cin>>x;
				push(x);
				break;
			case 3:
				r=pop();
				if(r!=-999)
					cout<<"\n Popped element from stack : "<<r<<endl;
				else
					cout<<"\n Stack is empty so no element popped from stack"<<endl;
				break;
			case 4:
				if(underflow())
					cout<<"\n Stack is underflow"<<endl;
				else
					cout<<"\n Stack is not underflow"<<endl;
				break;
			case 5:
				display();
				break;
			case 6:
				cout<<"\n Stack size : "<<size()<<endl;
				break;
			case 7:
				r=peek();
				if(r!=-999)
					cout<<"\n Stack peek : "<<r<<endl;
				else
					cout<<"\n Stack is empty so no peek"<<endl;
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
