#include<stdio.h>

struct tree1
{   
	int data;
	struct tree1 *lson,*rson;

	tree1(){lson=rson=NULL;data=0;}
};
struct tree1 *root,*p,dizhi[1000+5];
int t=0;
void build(tree1 *&bt)
{
	int x;
	scanf("%d",&x);
	if(x!=-1)
	{
		bt=&dizhi[++t];
		bt->data=x;
		build(bt->lson);
		build(bt->rson);
	}
	else bt=NULL;
}
void preorder(tree1 *bt)
{
	if(bt)
	  {
	  	 printf("%d ",bt->data);
	  	 preorder(bt->lson);
	  	 preorder(bt->rson);
	  }
}
int main()
{
    int n,x;
	//scanf("%d",&x);
	//root=&dizhi[++t];
	//root->data=x;
	build(root);
	preorder(root);
	return 0;
	
}
