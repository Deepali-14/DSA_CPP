#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool duplicate(int arr[], int n)
{
	sort(arr, arr+n);
	for(int i=1; i<n; i++)
	{
		if(arr[i]==arr[i-1])
			return true;
	}
	return false;
}
int main()
{
	cout<<"\n Enter no. of elements in the array : ";
	int n;
	cin>>n;
	
	int arr[n];
	
	cout<<"\n Enter elments in the array : ";
	for(int i=0; i<n ; i++)
		cin>>arr[i];
		
	cout<<"\n Elments in the array : ";
	for(int i=0; i<n ; i++)
		cout<<" "<<arr[i];
	cout<<endl;
	
	bool b=duplicate(arr,n);
	
	if(b)
		cout<<"\n The array is having duplicate elements"<<endl;
	else
		cout<<"\n The array is not having duplicate elements"<<endl;
	
	return 0;
}
