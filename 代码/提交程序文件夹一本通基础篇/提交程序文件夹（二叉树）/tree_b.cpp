#include<bits/stdc++.h>
using namespace std;
struct tree1
{
	char data;
	tree1 *lson,*rson;
	tree1(){
		data=0;
		lson=rson=NULL;
	}
};
int t;
struct tree1 *root,dz[1001];
void build_tree(tree1 *&bt)
{
	char x;
	scanf("%c",&x);
	if(x!='.')
	{
		bt=&dz[++t];
		bt->data=x;
		build_tree(bt->lson);
		build_tree(bt->rson);
	}
}
void a_out_tree(tree1 *bt)
{
	if(bt)
	{
		a_out_tree(bt->lson);
		printf("%c",bt->data);
		a_out_tree(bt->rson);
	}
}
void b_out_tree(tree1 *bt)
{
	if(bt)
	{
		b_out_tree(bt->lson);
		b_out_tree(bt->rson);
		printf("%c",bt->data);
	}
}
int main()
{
	freopen("tree_b.in","r",stdin);
	freopen("tree_b.out","w",stdout);
	build_tree(root);
	a_out_tree(root);
	cout<<endl;
	b_out_tree(root);
}
