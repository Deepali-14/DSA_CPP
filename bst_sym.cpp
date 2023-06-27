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
bool issymmetric(bst * R);
bool helper(bst * R,bst *l, bst *r);
int main()
{
	bst *R=insert(R,1);
	R->lc=insert(R,2);
	R->rc=insert(R,2);
	R->lc->lc=insert(R,3);
	R->lc->rc=insert(R,4);
	R->rc->lc=insert(R,4);
	R->rc->rc=insert(R,3);
	inorder(R);
	bool rs=issymmetric(R);
	if(rs)
		cout<<"\n Yes the binary search tree is symmetric"<<endl;
	else
		cout<<"\n No the binary search tree is not symmetric"<<endl;
	bst *r=insert(r,1);
	r->lc=insert(r,2);
	r->rc=insert(r,2);
	r->lc->rc=insert(r,3);
	r->rc->rc=insert(r,3);
	inorder(r);
	bool res=issymmetric(r);
	if(res)
		cout<<"\n Yes the binary search tree is symmetric"<<endl;
	else
		cout<<"\n No the binary search tree is not symmetric"<<endl;
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
bool issymmetric(bst * R)
{
	if(R==NULL)
	 	return true;
	return helper(R, R->lc, R->rc);
}
bool helper(bst *R, bst * l, bst * r)
{
	if(l==NULL && r==NULL)
		return true;
	if(l==NULL || r==NULL || l->val!=r->val)
		return false;
	return helper(R, l->lc, r->rc) && helper(R, l->rc, r->lc);
}
