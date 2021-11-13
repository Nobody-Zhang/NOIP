#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

const int MAXN=1005;
struct node{
	int data;
	struct node *l,*r;
	node(){
		l=NULL,r=NULL,data=0;
	}
}*root;
string prev,in;
void prep(struct node *bt)
{
	if (bt)
	{
	
		prep(bt->l);
		prep(bt->r);
		printf("%c",bt->data);
	}
	else
	
		bt=NULL;
	
}
void midprev_build(node* &bt,int i,int j,int len)//
{
	if (len<=0)
	  return;
	int mid=in.find(prev[i]);
	bt =new node;
	bt->data=prev[i];
	
	midprev_build(bt->l,i+1,j,mid-j);//m-j×óÊ÷³¤¶È;
	midprev_build(bt->r,i+(mid-j)+1,mid+1,len-1-(mid-j)); 
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
   	cin>>prev>>in;
   	int len=prev.length();
   	midprev_build(root,0,0,len);
   	prep(root);
   	
}
