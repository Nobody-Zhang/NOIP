#include<bits/stdc++.h>
using namespace std;
int am,an,ac;
double ax,ay,away[10005][2];
int bm,bn,bc;
double bx,by,bway[10005][2];
int loop;
double ans;
int read()
{
    int f=1,re=0;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)) re=(re<<3)+(re<<1)+ch-'0',ch=getchar();
    return f*re;
}
char readc()
{
    char ch=getchar();
    while(!isalpha(ch)) ch=getchar();
    return ch;
}
int gcd(int x,int y){return y?x:gcd(y,x%y);}
double calc(){return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));}
int main()
{
	freopen("astray.in","r",stdin);
	freopen("astray.out","w",stdout);
    ax=read(),ay=read(),am=read();
    for(int i=0;i<am;i++)
    {
        int y=read(),delta=1;char x=readc();
        if(x=='X')
        {
            if(y<0) delta=-1,y=-y;
            while(y--) away[an++][0]=delta;
        }
        else if(x=='Y')
        {
            if(y<0) delta=-1,y=-y;
            while(y--) away[an++][1]=delta;
        }
    }
    bx=read(),by=read(),bm=read();
    for(int i=0;i<bm;i++)
    {
        int y=read(),delta=1;char x=readc();
        if(x=='X')
        {
            if(y<0) delta=-1,y=-y;
            while(y--) bway[bn++][0]=delta;
        }
        else if(x=='Y')
        {
            if(y<0) delta=-1,y=-y;
            while(y--) bway[bn++][1]=delta;
        }
    }
    loop=an*bn/gcd(an,bn);
    ans=calc();
    for(int i=0;i<10000000;i++)
    {
        ax+=away[ac][0],ay+=away[ac][1];
        bx+=bway[bc][0],by+=bway[bc][1];
        ac=(ac+1)%an,bc=(bc+1)%bn;
        ans=min(ans,calc());
    }
    printf("%.2f",ans);
    return 0;
}
