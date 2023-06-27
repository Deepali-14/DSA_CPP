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
	bst *R = insert(R,1);
    R->lc = insert(R,2);
    R->rc = insert(R,3);
    R->lc->lc = insert(R,4);
    R->lc->rc = insert(R,5);
    R->rc->rc = insert(R,6);
	cout<<"\n Binary tree 1 : ";
	inorder(R);
	bst *r = insert(r,4);
    r->lc = insert(r,1);
    r->rc = insert(r,7);
    r->lc->lc = insert(r,3);
    r->rc->lc = insert(r,2);
    r->rc->rc = insert(r,6);
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
	return temp;
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
