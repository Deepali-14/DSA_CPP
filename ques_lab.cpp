#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cout<<"\n Enter value of a,b and c: ";
	cin>>a>>b>>c;
	if(a>b)
	{
		if(a>c)
			cout<<"a is greater";
		else if(c>a)
			cout<<" c is greater";
	}
	cout<<"  is greater";
	return 0;
}
