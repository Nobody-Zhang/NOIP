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
	for(int i=a;i<=b;i++)//�𽥵ݹ�����С������ 
	{
		if(h[root]==m[i])//rootΪָ�룬����ָ���˳����������������ν��� 
		{
			int x=root;
			root++;
			tree[x].d=m[i];
			if(i-1>=a)//������֧�����ַ� 
			tree[x].l=root;
			search(a,i-1);
			if(b>=i-1)//������֧�����ַ� 
			tree[x].r=root;
			search(i+1,b);
			return;
		}
	}
}
void print(int i)//����������� 
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
