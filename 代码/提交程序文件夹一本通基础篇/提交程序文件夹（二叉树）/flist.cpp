#include<bits/stdc++.h>
using namespace std;
/*string s1,s2;
struct tree1
{
	char data;
	struct tree1 *lchi,*rchi;
	tree1()
	{
		lchi=rchi=NULL;
		data='\000';
	}
};
struct tree1 *root,dz[10001];
int t=0;
void creat_tree(tree1 *&bt,int i,int j,int len)
{
	if(len<=0)
	 return;
	int mid=s2.find(s1[i]);
	t++;
	bt=&dz[t];
	bt->data=s1[i];
	int longleft=mid-j;//这个是左子树长度 
	int longright=len-longleft-1;//右子树长度 
	if(longleft!=0)//有左子树 
	 creat_tree(bt->lchi,i+2,j,longleft);
	if(longleft==0)
	 creat_tree(bt->lchi,i+1,j,longleft);
	 creat_tree(bt->rchi,longleft+i+1,mid+1,longright);
	if(longright!=0)
	 creat_tree(bt->rchi,longleft+i+2,mid+1,longright);
	if(longright==0)
	 creat_tree(bt->lchi,i+1,j,longleft);
	if(longright>0)
	 creat_tree(bt->lchi,i+2,j,longleft);
	if(longleft==0)
	creat_tree(bt->rchi,longleft+i+1,mid+1,longright);
	if(longleft>0)
	creat_tree(bt->rchi,longleft+i+2,mid+1,longright);

	build_tree(bt->lchi,i+1,j,mid-j);
	build_tree(bt->rchi,i+(mid-j)+1,mid+1,len-1-(mid-j));

	creat
}
void print_tree(tree1 *bt)
{
	if(bt)
	{
		cout<<bt->data;
		print_tree(bt->lchi);
		print_tree(bt->rchi);
	}
	else bt=NULL;
}
int main()
{
	freopen("flist.in","r",stdin);
	cin>>s1>>s2;
	creat_tree(root,0,0,s1.length());
	print_tree(root);
	return 0;
}*/
int mp[255];
char s1[255],s2[255];
int l;
void creat_tree(int l,int r)
{
	if(l>r) return;
	int k=0x7fffffff,where;
	for(int i=l;i<=r;i++)
	{
		if(mp[s1[i]]<k)
		{
			k=mp[s1[i]];
			where=i;
		}
	}
	cout<<s1[where];
	creat_tree(l,where-1);
	creat_tree(where+1,r);
}
int main()
{
	freopen("flist.in","r",stdin);
	freopen("flist.out","w",stdout);
	gets(s1);
	gets(s2);
	l=strlen(s1);
	for(int i=0;i<l;i++)
	 mp[s2[i]]=i;
	creat_tree(0,l-1);
	cout<<endl;
	return 0;
}
