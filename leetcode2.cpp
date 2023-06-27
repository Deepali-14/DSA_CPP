#include<iostream>
#include<bits/stdc++.h>
#include<malloc.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *start=NULL;
void init()
{
	start=NULL;
}
node *createnode(int x)
{
	node *temp;
	temp=(node *)malloc(sizeof(temp));
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
bool palindrome_check()
{
	if(start==NULL)
	{
		cout<<"\n No Palindrome check since linked list is empty"<<endl;
		return false;
	}
	else if(start->next==NULL)
	{
		cout<<"\n Yes the linked list is itself palindrome since it contains only one element"<<endl;
		return false;
	}

	else
	{
		stack<int> s;
		node *p=start;
		for(p=start; p!=NULL; p=p->next)
			s.push(p->data);
		
		for(p=start; p!=NULL; p=p->next)
		{
			int x=s.top();
			s.pop();
			
			if(p->data!=x)
			{
				cout<<"\n No the linked list is not a palindrome"<<endl;
				return false;
			}
		}
		return true;
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
	bool b=palindrome_check();
	if(b)
		cout<<"\n Yes the linked list is a palindrome"<<endl;
	
	return 0;
}
