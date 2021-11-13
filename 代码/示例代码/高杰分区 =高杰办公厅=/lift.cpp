#include<bits/stdc++.h>
using namespace std;
int a,n,b,s[100005],f[10005],map1[205],used[205],tot=0;
void print(int wei)
{
	tot++;
    if(f[wei]!=0)
    print(f[wei]);
    return;
}
void bfs(int p)
{
    int tou=0,wei=1;
    f[0]=1;
    s[1]=p;
    used[p]=1;
    do{
        tou++;
        int x1=s[tou]+map1[s[tou]];
        if(x1<=n&&x1>=1&&used[x1]==0)
        {
        //	printf("*%d ",x1);
            used[x1]=1;
            wei++;
            s[wei]=x1;
            f[wei]=tou;
            if(s[wei]==b)
            {
                print(wei);
                printf("%d",tot-1);
                return;        
            }
        }
         x1=s[tou]-map1[s[tou]];
        if(x1<=n&&x1>=1&&used[x1]==0)
        {
        //	printf("*%d ",x1);
            used[x1]=1;
            wei++;
            s[wei]=x1;
            f[wei]=tou;
            if(s[wei]==b)
            {
                print(wei);
                printf("%d",tot-1);
                return;          
            }
        }
        
    }while(tou<wei);
    printf("-1");
    
}
int main()
{
    freopen("lift.in","r",stdin);
	freopen("lift.out","w",stdout);
	
	scanf("%d%d%d",&n,&a,&b);
if(a==b)
{
    printf("0");
    return 0;
}
    for(int t=1;t<=n;t++)
    scanf("%d",&map1[t]);
    bfs(a);
    
}
