#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
template <typename T> inline void redi(T& t)
{
	register int c=getchar();t=0;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) t=t*10+c-'0',c=getchar();
}
template <typename T,typename... Args>inline void redi(T& t,Args&... args)
{
	redi(t);
	redi(args...);
}
int n,k,color[N],paint[N][3],fa[N];
int getfa(int now)
{
    if(fa[now]==now) return now;
    return fa[now]=getfa(fa[now]);
}
void unionn(int a,int b)
{
    if(getfa(a)!=getfa(b)) fa[fa[a]]=fa[b];
    return;
}
void judge(int now,int col)
{
    color[now]=col;
    if(color[now-1]!=0) unionn(now-1,now);
    if(color[now+1]!=0) unionn(now,now+1);
    return;
}
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    redi(n,k);
    for(int i=1;i<=k;i++)
        redi(paint[i][1],paint[i][2],paint[i][0]);//cin>>>>>>;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=k;i>=1;i--){
        int lef=paint[i][1],rig=paint[i][2];
        while(lef<=rig){
            if(!color[lef])judge(lef,paint[i][0]);
            lef=getfa(lef)+1;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",color[i]);
    return 0;
}
