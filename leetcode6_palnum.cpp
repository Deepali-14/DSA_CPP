#include<iostream>
using namespace std;
int main()
{
	cout<<"\n Enter number : ";
	int n,x,y;
	cin>>n;
	if(n<0)
	{
		cout<<"\n The number is not palindrome as it is negative"<<endl;
		return 0;
	}
		
	else
	{
		x=n;
		y=0;
		while(n!=0)
		{
			int r=n%10;
			n=n/10;
			y=y*10+r;
		}
	}
	if(x==y)
		cout<<"\n The number is palindrome"<<endl;
	else
		cout<<"\n The number is not palindrome"<<endl;
	return 0;
}
