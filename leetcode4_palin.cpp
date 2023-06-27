#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
//	string s="A man, a plan, a canal : Panama";
//  string s="Race a car";
//  string s="123abba abba  ::: 321";
	string s="We  123  )))  421   ew";
	for(int i=0; i<s.length(); i++)
	{
		s[i]=tolower(s[i]);
	}
	cout<<s<<endl;
//	transform(s.begin(), s.end(), s.begin(), ::tolower);
//	char* carr;
//	carr=&s[0];
//	for(int i=0; i<s.length(); i++)
//	{
//		cout<<carr[i];
//	}
	int start=0;
	int end=s.length()-1;
	int flag=1;
	while(start<end)
	{
		while(start<end && !isalpha(s.at(start)) && !isdigit(s.at(start)))
			start++;
		cout<<"Start = "<<start<<endl;
		while(start<end && !isalpha(s.at(end)) && !isdigit(s.at(end)))
			end--;
		cout<<"End = "<<end<<endl;
		if(start>=end)
		{
			cout<<"Exit"<<endl;
			break;
		}
		if(s.at(start)!=s.at(end))
		{
			cout<<"Wrong"<<endl;
			flag=0;
			break;
		}
		start++;
		end--;
	}
	if(flag==1 && start>=end)
		cout<<"\nThe string is a palindrome"<<endl;
	else
		cout<<"\nThe string is not a palindrome"<<endl;
	return 0;
}
