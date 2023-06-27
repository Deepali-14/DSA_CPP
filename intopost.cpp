#include<iostream>
using namespace std;
#define max 20
char stk[max];
int top=-1;
void push(char c)
{
	stk[++top]=c;
}
char pop()
{
	char c=stk[top--];
	return c;
}
int prec(char ch)
{
	if(ch=='^')
		return 3;
	else if(ch=='*' || ch=='/')
		return 2;
	else if(ch=='+' || ch=='-')
		return 1;
}
int main()
{
	char exp[max], post[max], ch;
	int j=0;
	cout<<"\n Enter the infix expression : ";
	cin>>exp;
	for(int i=0; exp[i]!='\0'; i++)
	{
		ch=exp[i];
		if(ch=='{'||ch=='[')
			ch='(';
		else if(ch=='}' || ch==']')
			ch=')';
		if(isalpha(ch))
			post[j++]=ch;
		else if(ch=='(')
		{
			push(ch);
		}
		else if(ch==')')
		{
			while(stk[top]!='(')
				post[j++]=pop();
			top--;
		}
		else 
		{
			for(int k=top; (k>-1 && stk[top]!='(') && (prec(stk[top])>=prec(ch)); k++)
				post[j++]=pop();	
			push(ch);
		}
	}
    while(top>-1)
    	post[j++]=pop();
    post[j]='\0';
    cout<<" ";
    for(int i=0; post[i]!='\0'; i++)
    	cout<<post[i];
    cout<<endl;
	return 0;
}
