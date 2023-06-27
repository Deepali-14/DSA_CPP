#include<iostream>
using namespace std;
#define max 20
char stk[max];
int top=-1;
void push(char ch)
{
	stk[++top]=ch;
}
void pop()
{
	char ch=stk[top--];
}
int main()
{
	char exp[max], ch;
	int opr=0, opd=0, i=0;
	cout<<"\n Enter expression : ";
	cin>>exp;
	for(i=0; exp[i]!='\0'; i++)
	{
		ch=exp[i];
		
		if(isalpha(ch))
			opd++;
			
		else if(ch=='(' || ch=='{' || ch=='[')
			push(ch);
			
		else if(ch==')' || ch=='}' || ch==']')
		{
			if(top==-1)
				break;
			else 
			{
				if((ch==')'&&stk[top]=='(') || (ch=='}'&&stk[top]=='{') || (ch==']'&&stk[top]=='['))
					pop();
				else
					break;
			}
		}
		
		else
			opr++;
	}
	if(top==-1 && exp[i]=='\0' && opd==opr+1)
		cout<<"\n Your expression is valid"<<endl;
	else
		cout<<"\n Your expression is not valid"<<endl;
	return 0;
}
