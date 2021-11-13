#include<cstdio>
#define ri register int
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
using namespace std;
template<typename TP>inline void read(TP&x)
{
    x=0;int f=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;
}
template<typename TP>inline void print(TP x)
{
    if(x<0)x=-x,putchar('-');
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
int n,m,ans;
int num[15];
inline int gcd(int a,int b){while(b^=a^=b^=a%=b);return a;}
inline long long lcm(int a,int b){return a*b/gcd(a,b);}
inline void dfs(int x,int cnt,int tot)
{
	if(cnt&1)ans-=m/tot;
	else ans+=m/tot;
	for(ri i=x+1;i<=n;++i)
		dfs(i,cnt+1,lcm(tot,num[i]));
}
int main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	read(n),read(m),ans=m;
	for(ri i=1;i<=n;++i)read(num[i]);
	for(ri i=1;i<=n;++i)
		dfs(i,1,num[i]);
	print(ans);
}
/*
4 100
5 6 48 40
*/
