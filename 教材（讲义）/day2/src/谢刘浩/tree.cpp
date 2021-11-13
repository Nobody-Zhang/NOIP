#include<bits/stdc++.h>
using namespace std;
int l[1000001],r[1000001],n,a[1000001],ans=1;
bool tof;
int dfs(int x,int y,int s)
{
    if(x==-1&&y==-1)return 0; 
    if(x==-1||y==-1){tof=1;return 0;} 
    if(a[x]!=a[y]){tof=1;return 0;}
    return dfs(l[x],r[y],2)+dfs(r[x],l[y],2)+s;
   
}
void read(int &x)
{
    int f=1;x=0;
    char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=(x<<3)+(x<<1)+s-'0';s=getchar();}
	x*=f;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++)read(a[i]);
    for(int i=1;i<=n;i++){read(l[i]);read(r[i]);}
    for(int i=1;i<=n;i++){
        int s=dfs(l[i],r[i],3);
        if(s>ans&&tof==0)ans=s;
        tof=0;
    }
    printf("%d",ans);
    return 0;
}
