#include<iostream>
using namespace std;
void targetindex_sum(int arr[], int a[], int x, int n)
{
	int start=0;
	int end=n-1;
	while(start<end)
	{
		int sum=arr[start]+arr[end];
		if(sum==x)
		{
			a[0]=start+1;
			a[1]=end+1;
			return;
		}
		if(sum>x)
			end--;
		else
			start++;
	}
}
int main()
{
	cout<<"\n Enter no. of elements in the array : ";
	int n;
	cin>>n;
	
	int arr[n];
	cout<<"\n Enter target sum : ";
	int x;
	cin>>x;
	
	cout<<"\n Enter elments in the array : ";
	for(int i=0; i<n ; i++)
		cin>>arr[i];
		
	cout<<"\n Elments in the array : ";
	for(int i=0; i<n ; i++)
		cout<<" "<<arr[i];
	cout<<endl;
	
	int a[2];
	targetindex_sum(arr, a, x, n);
	
	for(int i=0; i<2 ; i++)
		cout<<" "<<a[i];
	cout<<endl;
	
	return 0;
}
