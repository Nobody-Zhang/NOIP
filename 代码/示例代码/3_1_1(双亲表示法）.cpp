#include<bits/stdc++.h>
using namespace std;
int n,m;
struct tree1{
	int data,parent;
	tree1(){data=parent=0;}
};
struct tree1 tree[102];
int main()
{
  freopen("3_1.in","r",stdin);
  int i,x,y,root,maxroot,sum=0,j,Max=0;
  cin>>n>>m;
  for(i=1;i<=m;i++)
  {
    cin>>x>>y;
    tree[y].parent=x;
   }
  for(i=1;i<=n;i++)                     //找出树根 
     if(tree[i].parent==0)
      {
        root=i;break;
      }
  for(i=1;i<=n;i++)                     //找孩子最多的结点
   {
     sum=0; 
     for(j=1;j<=n;j++)
        if(tree[j].parent==i) sum++;
     if(sum>Max)
      {
         Max=sum;maxroot=i;
      }
   }    
   cout<<root<<endl<<maxroot<<endl;  
   for(i=1;i<=n;i++)
     if(tree[i].parent==maxroot) cout<<i<<" ";
   return 0; 
}

