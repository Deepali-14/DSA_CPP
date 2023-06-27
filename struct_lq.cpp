#include<iostream>
#define max 5
using namespace std;
struct Queue
{
	int data[max];
	int R,F;
}lq;
void init()
{
	lq.R=-1;
	lq.F=-1;
}
int overflow()
{
	if(lq.R==max-1)
		return 1;
	else
		return 0;
}
int underflow()
{
	if(lq.F==-1)
		return 1;
	else
		return 0;
}
void enqueue(int x)
{
	if(overflow())
		cout<<"\n The linear queue is overflow"<<endl;
	else
	{
		if(lq.R==-1)
		{
			lq.R=lq.F=0;
			lq.data[lq.R]=x;
		}
		
		else
			lq.data[++lq.R]=x;
	}
}
int dequeue()
{
	if(underflow())
		return -999;
	else
	{
		int x;
		x=lq.data[lq.F];
		if(lq.F==lq.R)
		lq.F=lq.R=-1;
		else
		lq.F++;
		return x;
	}
}
int size()
{
	if(lq.F==-1)
		return 0;
	else
		return lq.R-lq.F+1;
}
int peek()
{
	if(lq.F==-1)
		return -9999;
	else
		return lq.data[lq.F];
}
void display()
{
	if(lq.F==-1)
		cout<<"\n The linear queue is empty"<<endl;
	
	else
	{
		cout<<"\n The linear queue is : "<<endl;
		for(int i=lq.F;i<=lq.R;i++)
			cout<<" "<<lq.data[i]<<" "<<endl;
		cout<<endl;
	}	
}

int main()
{
	cout<<"********************** Linear Queue **********************"<<endl;
	lq.F=-1;
	lq.R=-1;
	int ch,y,k;
	do
	{
		cout<<"\n 1. Initialization \n 2. Enqueue \n 3. Dequeue \n 4. Display \n 5. Underflow \n 6. Overflow \n 7. Size \n 8. Peek \n 0. Exit"<<endl;
		cout<<"\n Enter your choice : ";
		
		cin>>ch;
		switch(ch)
		{
			case 1:
		  	    	init();
		  	        break;
		  	case 2: 
		  	        cout<<"\n Enter the element you want to insert : ";
		  	        cin>>y;
		  	        enqueue(y);
		  	        break;
		  	case 3: 
		  	        k=dequeue();
		  	        if(k!=-999)
		  	        cout<<"\n The deleted element is "<<k<<endl;
		  	        else
		  	        cout<<"\n There is no element for deletion"<<endl;
		  	        break;
		  	case 4: 
		  	        display();
		  	        break;
		  	case 5: 
		  	        if(underflow())
		  	        cout<<"\n The linear queue is underflow"<<endl;
		  	        else
		  	        cout<<"\n The linear queue is not underflow"<<endl;
		  	        break;
		  	case 6: 
		  	        if(overflow())
		  	        printf("\n The linear queue is overflow");
		  	        else
		  	        printf("\n The linear queue is not overflow");
		  	        break;
		  	case 7: 
					cout<<"\n The size of linear queue is "<<size()<<endl; 
		  	        break;
		  	case 8: 
		  	        if(peek()!=-9999)
					cout<<"\n The peek of linear queue is "<<peek()<<endl; 
					else
					cout<<"\n The linear queue is empty"<<endl;
		  	        break;
		  	case 9: 
		        	cout<<"\n Exiting......!"<<endl;
		  	        break;
		  	default:  
			        cout<<"\n We are in default case"<<endl;
		}
	}while(ch!=0);
	return 0;
}
