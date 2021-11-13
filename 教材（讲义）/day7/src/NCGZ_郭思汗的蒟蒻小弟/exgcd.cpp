#include<cstdio>
using namespace std;
#define rg register int
#define ll long long
#define V inline void
#define I inline int
#define F1(i,a,b) for(rg i=a;i<=b;++i)
#define bl putchar(' ')
#define ed putchar('\n')
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
template<typename TP>V read(TP &x)
{
	TP f=1;x=0;register char c=getchar();
	for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c^'0');
	x*=f;
}
template<typename TP>V print(TP x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) print(x/10);
	putchar(x%10+'0'); 
}
int T,a,b,x,y,c;
template<typename TP>I exgcd(TP a,TP b,TP&x,TP&y)
{
	if(!b) {x=1;y=0;return a;}
	TP temp=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return temp;
}
int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	read(T);
	while(T--)
	{
		read(a),read(b),read(c);
		x=y=0;
		rg g=exgcd(a,b,x,y);
		if(c%g) puts("no");
		else print((x*(c/g)%b+b)%b),ed;
	}
	return 0;
}
