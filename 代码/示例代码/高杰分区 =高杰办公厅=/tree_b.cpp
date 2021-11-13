#include<bits/stdc++.h>
using namespace std;
string s1;
struct tree{
	char data;
	tree *lson,*rson;
	tree(){data=0;lson=rson=NULL;
	}
};
tree *root,fz[1005];
int n=-1;
void jianli( tree *&zj){//zj 枝节 
	n++;
	if(s1[n]!='.')
	{

		zj=&fz[n];
		zj->data=s1[n];
		jianli(zj->lson);
		jianli(zj->rson);
	}
	else zj=NULL;
}
void zxbl(tree *zj){//（tree zj）这样zj就成了一个普通结构体 
	if(zj!=NULL)
	{
		zxbl(zj->lson);
		printf("%c",zj->data);
		zxbl(zj->rson);	
	}
}
void hxbl(tree *zj){
	if(zj!=NULL)
	{
		hxbl(zj->lson);
		hxbl(zj->rson);	
		printf("%c",zj->data);
	}
}
int main()
{
   freopen("tree_b.in","r",stdin);
  // freopen("tree_b.out","w",stdout);
   cin>>s1;
  //root=&fz[0];
 //  root->data=s1[0];
   jianli(root);
   //printf("%d",n);
   zxbl(root);//错误样例（*root）↑ *root也成了普通结构体 无指针作用 
   printf("\n");
   hxbl(root);
}
