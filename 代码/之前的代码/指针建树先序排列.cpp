#include<bits/stdc++.h>
using namespace std;
struct tree1
{
	int data;
	tree1 *lson,*rson;
	tree1()
	{
		lson=NULL;
		rson=NULL;
		data=0;
	}
};
struct tree1 *root,dz[1005];
int t;
void creat_tree(tree1 *&bt)
{
	int x;
	scanf("%d",&x);
	if(x!=-1)
	{
		bt=&dz[++t];
		bt->data=x;
		creat_tree(bt->lson);
		creat_tree(bt->rson);
	}
	else bt=NULL;
}
void out_tree(tree1 *bt)
{
	if(bt)
	{
		printf("%d ",bt->data);
		out_tree(bt->lson);
		out_tree(bt->rson);
	}
}
int main()
{
	creat_tree(root);
	out_tree(root);
}
