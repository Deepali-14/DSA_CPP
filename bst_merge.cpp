#include<iostream>
#include<malloc.h>
using namespace std;
struct bst
{
	int val;
	struct bst *lc;
	struct bst *rc;
};
typedef struct bst bst;
bst * insert(bst *R, int x);
void inorder(bst *R);
bst * merge(bst *R, bst *r);
int main()
{
	bst *R=NULL, *r=NULL;
	int x;
	cout<<"\n Enter no. of elements in the binary tree : ";
	int m;
	cin>>m;
	cout<<"\n Enter elements in the binary tree : ";
	for(int i=0; i<m; i++)
	{
		cout<<"\n Enter element "<<i+1<<" : ";
		cin>>x;
		R=insert(R,x);
	}
	cout<<"\n Binary tree 1 : ";
	inorder(R);
	cout<<"\n Enter no. of elements in the binary tree : ";
	int n;
	cin>>n;
	cout<<"\n Enter elements in the binary tree : ";
	for(int i=0; i<n; i++)
	{
		cout<<"\n Enter element "<<i+1<<" : ";
		cin>>x;
		r=insert(r,x);
	}
	cout<<"\n Binary tree 2 : ";
	inorder(r);
	cout<<"\n Merged binary tree : ";
	bst *temp=merge(R,r);
	inorder(temp);
}
bst * insert(bst *R, int x)
{
	bst *temp;
	temp=(bst *)malloc(sizeof(bst));
	temp->val=x;
	temp->lc=temp->rc=NULL;
	if(R==NULL)
		R=temp;
	else
	{
		if(x<R->val)
			R->lc=insert(R->lc,x);
		else if(x>R->val)
			R->rc=insert(R->rc,x);
	}
	return R;
}
void inorder(bst *R)
{
    if(R!=NULL)
    {
       inorder(R->lc);
       cout<<" "<<R->val;
       inorder(R->rc);
    }
}
bst * merge(bst *R, bst *r)
{
	if(R==NULL && r==NULL)
		return NULL;
		
	if(R==NULL && r!=NULL)
		return r;
	
	if(r==NULL && R!=NULL)
		return R;
	
	else
	{
		R->val=R->val+r->val;
		R->lc = merge(R->lc, r->lc);
    	R->rc = merge(R->rc, r->rc);
		return R;
	}
}
