#include<stdio.h>
#include<string.h>
char h[30],m[30];
struct treebuild{
	int d,l,r;
};
treebuild tree[30];
int root;
void search(int a,int b)
{
	for(int i=a;i<=b;i++)//逐渐递归至最小的子树 
	{
		if(h[root]==m[i])//root为指针，按照指针的顺序在先序遍历中依次进行 
		{
			int x=root;
			root++;
			tree[x].d=m[i];
			if(i-1>=a)//结点的左支存在字符 
			tree[x].l=root;
			search(a,i-1);
			if(b>=i-1)//结点的右支存在字符 
			tree[x].r=root;
			search(i+1,b);
			return;
		}
	}
}
void print(int i)//后续遍历输出 
{
	if(tree[i].l!=-1)
	   print(tree[i].l);
	if(tree[i].r!=-1)
	   print(tree[i].r);
	printf("%c",tree[i].d);
}
int main()
{
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	scanf("%s",h);
	scanf("%s",m);
	for(int i=0;i<=29;i++)
	{
		tree[i].d=0;
		tree[i].l=-1;
		tree[i].r=-1;
	}
	search(0,strlen(h)-1);
	print(0);
//	for(int i=0;i<=4;i++)
//	printf("%d %c %d %d\n",i,tree[i].d,tree[i].l,tree[i].r);
	return 0;
}
