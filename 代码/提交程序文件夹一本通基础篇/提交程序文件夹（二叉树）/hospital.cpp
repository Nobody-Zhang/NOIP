#include<bits/stdc++.h>
using namespace std;
int m,mp[105][105],a[105];
/*int n,t,p,len[105][105],tmp;
struct tree1
{
	int data;
	struct tree1*lchi,*rchi;
	tree1(){
		lchi=rchi=NULL;
		data=0;
	}
};
struct tree1 a[105],*root;
void creat_tree(tree1 *&bt)
{
	int x,y,z;
	cin>>x>>y>>z;
	bt=&a[++t];
	bt->data=x;
	if(y!=0&&z!=0)
	{
		creat_tree(bt->lchi);
		creat_tree(bt->rchi);
	}
	
}
void juli(tree1 *bt)
{
	if(bt)
	{
		p++;
		juli(bt->lchi);
		juli(bt->rchi);
	}
}
void search_tree(tree1 *bt)
{
	if(*bt)
	{
		search_tree(bt->lchi);
		search_tree(bt->rchi);
	}
}
int main()
{
	cin>>n;
	creat_tree(root);
	//print_tree(root);
	juli(root);
}*/
int main()
{
	freopen("hospital.in","r",stdin);
	freopen("hospital.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=m;j++)
	  mp[i][j]=1000000;
	for(int i=1;i<=m;i++)
	 {
	 	mp[i][i]=0;
	 	int y,z;
	 	cin>>a[i]>>y>>z;
	 	if(y!=0) mp[i][y]=mp[y][i]=1;
	 	if(z!=0) mp[i][z]=mp[z][i]=1;
	 }
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=m;j++)
	  if(i!=j)
	  {
	  	for(int k=1;k<=m;k++)
	  	if(i!=k&&j!=k&&mp[j][i]+mp[i][k]<mp[j][k])
	  	mp[j][k]=mp[j][i]+mp[i][k];
	  }
	int minn=0x7fffffff;
	for(int i=1;i<=m;i++)
	{
		int tot=0;
		for(int j=1;j<=m;j++)
		 tot+=mp[i][j]*a[j];
		if(tot<minn) minn=tot;
	}
	cout<<minn<<endl;
	return 0;
}
/*
5
13 2 3
4 0 0
12 4 5
20 0 0
40 0 0
*/
