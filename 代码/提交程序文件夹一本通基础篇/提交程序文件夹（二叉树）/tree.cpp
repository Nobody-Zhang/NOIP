#include<bits/stdc++.h>
using namespace std;
string s1,s2;
struct tree1
{
	char data;
	struct tree1 *lchi,*rchi;
	tree1(){
		data='\000';
		lchi=rchi=NULL;
	}
};
struct tree1 dz[1001],*root;
int pp;
void build_tree(tree1 *&bt,int i,int j,int len)
{
	if(len<=0)
	 return;
	int mid=s2.find(s1[i]);
	bt=&dz[++pp];
	bt->data=s1[i];
	build_tree(bt->lchi,i+1,j,mid-j);
	build_tree(bt->rchi,i+(mid-j)+1,mid+1,len-1-(mid-j));
}
void print_tree(tree1 *bt)
{
	if(bt)
	{
		print_tree(bt->lchi);
		print_tree(bt->rchi);
		cout<<bt->data;
	}
	else bt=NULL;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>s1>>s2;
	build_tree(root,0,0,s1.length());
	print_tree(root);
}
