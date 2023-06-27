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
bst * mirror(bst *R);
int main()
{
	bst *R=NULL;
	int x;
	cout<<"\n Enter no. of elements in the binary tree : ";
	int n;
	cin>>n;
	cout<<"\n Enter elements in the binary tree : ";
	for(int i=0; i<n; i++)
	{
		cout<<"\n Enter element "<<i+1<<" : ";
		cin>>x;
		R=insert(R,x);
	}
	inorder(R);
	mirror(R);
	cout<<endl;
	inorder(R);
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
       printf(" %d ",R->val);
       inorder(R->rc);
    }
}
bst * mirror(bst *R)
{
	if(R==NULL)
		return R;
	bst *temp;
	temp=R->lc;
	R->lc=R->rc;
	R->rc=temp;
	mirror(R->lc);
	mirror(R->rc);
}
