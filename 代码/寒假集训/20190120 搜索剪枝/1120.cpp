// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int m,in[70],minn,used[70],tmp;
bool usedans[1001];
int tot,ans[1001];
//#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p1)?EOF:*p1++)
//char buf[1<<21],*p1=buf,*p2=buf;
template <typename T>inline void redi(T& t)
{
    register int c=getchar();
    t=0;
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) t=t*10+c-'0',c=getchar();
}
template <typename T,typename...Args>inline void redi(T& t,Args&... args)
{
    redi(t);
    redi(args...);
}
bool cmp(int a,int b)
{
    return a>b;
}
void dfs(int pos,int len,int cnt)
{
    if(cnt==tot/ans[tmp])
    {
        printf("%d",ans[tmp]);
        exit(0);
    }
    if(len==ans[tmp])
    {
        dfs(1,0,cnt+1);
        return;
    }
    for(int i=1;i<=in[0];i++)
    {
        if(used[i]==true) continue;
        if(len+in[i]>ans[tmp]) continue;
        used[i]=true;
        dfs(i+1,len+in[i],cnt);
        used[i]=false;
        if(len==0) return;
    }
    return;
}
int main()
{
    //freopen("1.in","r",stdin);
    //srand(time(0));
    redi(m);//scanf("%d",&m);
    for(int i=1;i<=m;i++)
     {
     	int k;
     	redi(k);//scanf("%d",&in[i]);
     	if(k>50) continue;
     	in[0]++;
     	in[in[0]]=k;
     	tot+=in[in[0]];
     }
    sort(in+1,in+1+in[0],cmp);
    for(int i=in[1];i<=tot;i++)
     {
     	//if(i>=50) break;
     	if(tot%i==0){
     	    ans[0]++;
     	    ans[ans[0]]=i;
         }
     }
    /*while(1)
    {
        int k=rand()%ans[0]+1;
        if(usedans[k]==true) continue;
        usedans[k]=true;
        tmp=k;
        dfs(0,0,0);
    }*/
    for(int i=1;i<=ans[0];i++)
    {
        tmp=i;
        dfs(0,0,0);
    }
    return 0;
}
