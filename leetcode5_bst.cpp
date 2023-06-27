#include<iostream>
#include<malloc.h>
using namespace std;
struct bst
{
	int data;
	struct bst *lc;
	struct bst *rc;
};
typedef struct bst bst;
bst* insert(bst *R,int x)
{
	bst *temp;
	temp=(bst *)malloc(sizeof(bst));
	temp->data=x;
	temp->lc=temp->rc=NULL;
	if(R==NULL)
	R=temp;
	else
	{
		if(x<R->data)
		R->lc=insert(R->lc,x);
		else if(x>R->data)
		R->rc=insert(R->rc,x);
	}
	return R;
}
void inorder(bst *R)
{
	if(R!=NULL)
    {
       inorder(R->lc);
       cout<<" "<<R->data;
       inorder(R->rc);
    }
}
int main()
{
	bst *R=NULL;
	cout<<"\n Enter no. of elements in the linked list : ";
	int n;
	cin>>n;
	
	int x;
	
	for(int i=0; i<n; i++)
	{
		cout<<"\n Enter "<<i+1<<" element : ";
		cin>>x;
		R=insert(R,x);
	}
	
	inorder(R);
	return 0;
}
