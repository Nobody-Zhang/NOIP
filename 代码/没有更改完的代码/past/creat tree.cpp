#include<bits/stdc++.h>
using namespace std;
int m,n;
struct tree1{
	int data;
	int lch;
	int rch;
	tree1(){
		data=0;
		lch=rch=-1;
	}
};
typedef struct tree1 creat_tree;
creat_tree tree[1001];
void in_tree(int t)
{
	int l,k;
	for(int i=1;i<=t;i++)
	{
		cin>>l>>k;
		tree[k].data=k;
		if(tree[l].lch==-1)
		 tree[l].lch=k;
		else
		 tree[l].rch=k;
	}
}
void out_tree()
{
	cout<<"ÐòºÅ	×ó	Êý¾Ý	ÓÒ"<<endl;
	for(int i=1;i<=m;i++)
	 cout<<i<<"	"<<"<"<<tree[i].lch<<">"<<"	"<<tree[i].data<<"	"<<"<"<<tree[i].rch<<">"<<endl;
}
int main()
{
	cin>>m>>n;
	in_tree(n);
	out_tree();
}
/*
6
5
3 1
5 1
6 5
2 5
7 3
*/
