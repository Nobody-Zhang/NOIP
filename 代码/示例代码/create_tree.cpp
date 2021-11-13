#include <stdio.h>
int n,m;
struct tree
{
    int data;
    int left;
    int right;
    //tree(){data=0;left=right=-1;}
};
typedef struct tree treenode;
treenode atree[15];
 
// ����������
void create_tree(int n, int m)
{    
     int x,y;   
     
     for(int i=1;i<=m;i++)
      {
      	scanf("%d%d",&x,&y);
      	atree[y].data=y;
      	if(atree[x].left==-1)
            atree[x].left = y;
        else
            atree[x].right = y;
      }      
}
//��ӡ������
void print_atree()
{
    printf("��� ��  ����  ��\n");
    for(int i=1;i<=n;i++)
    {
        printf("%2d,{%2d} {%2d} {%2d}\n",i,atree[i].left,atree[i].data,atree[i].right);
    }
}
 
//������� 
void preorder(int k)
{   
    printf("%d ",k);
    if (atree[k].left!=-1)
     preorder(atree[k].left);
    if (atree[k].right!=-1)
     preorder(atree[k].right);
  	
}

int main()
{
    //freopen("create_tree.in","r",stdin);
    //create a bree
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++) 
    {
        atree[i].data = 0;
        atree[i].right = -1;
        atree[i].left = -1;
    }
    create_tree(n,m);
    print_atree();
    int p=-1;
    for(int i=1;i<=n;i++)
	   if(atree[i].data==0)
	   {
	      p=i;
	      break;
	   }
    preorder(p);
    return 0;
}

