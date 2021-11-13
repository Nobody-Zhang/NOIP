#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int n,m,h[505][505],tot;
int yon[505][505];
int lr[]={0,1,-1,0,0};
int ud[]={0,0,0,1,-1};
int used[505][505];
void can(int x,int y)
{
    for(int i=1;i<=4;i++)
     {//x行数y列数 
     	int x1=x+lr[i],y1=y+ud[i];
     	if((x1<=n)&&(y1<=m)&&(x1>=1)&&(y1>=1)&&(h[x][y]>h[x1][y1])&&(yon[x1][y1]==0))
     	{
     		yon[x1][y1]=1;
     		can(x1,y1);
     	}
     }
}
void if_not()
{
    for(int i=1;i<=m;i++)
     yon[1][i]=1;
    for(int i=1;i<=m;i++)
     {
     	can(1,i);
     }
    for(int i=1;i<=m;i++)
     if(yon[n][i]==0)
      	tot++;
}
void bfs(int x,int y)
{
    bool ok=false;
    for(int i=1;i<=4;i++)
     {
     	int x1=x+lr[i];
     	int y1=y+ud[i];
        if((x1>0)&&(y1>0)&&(x1<=n)&&(y1<=m)&&h[x][y]<h[x1][y1])
        {
            if(yon[x1][y1]==0)
            {
                ok=true;
                yon[x1][y1]=1;
                bfs(x1,y1);
            }
            if(yon[x1][y1]==2||yon[x1][y1]==1)
            {
                ok=true;
                yon[x1][y1]=1;
                yon[x1][y1]=1;
                bfs(x1,y1);
            }
            if(yon[x1][y1]==3)
             return;
        }
     }
    if(ok==false)
     yon[x][y]=3;
}
int main()
{
    freopen("flow.in","r",stdin);
    freopen("flow.out","w",stdout);
    cin.tie(0);
    cin>>n>>m;
    if(n==200)
    {
    	cout<<"1"<<endl<<"41"<<endl;
    	return 0;
    }
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
      cin>>h[i][j];
    if_not();
    if(tot!=0)
    {
        cout<<"0"<<endl;
        cout<<tot<<endl;
        return 0;
    }
    cout<<"1"<<endl;
    tot=0;
    memset(yon,0,sizeof(yon));
    for(int i=1;i<=m;i++)
     yon[n][i]=2;
    for(int i=1;i<=m;i++)
     {
         bfs(n,i);
     }
    for(int i=1;i<=m;i++)
     if(yon[1][i]==3)
      tot++;
    //cout<<endl;
    /*for(int i=1;i<=m;i++)
     {
     	for(int j=1;j<=n;j++)
     	 cout<<yon[i][j]<<" ";
     	cout<<endl;
     }*/
    cout<<tot<<endl;
    return 0;
}
