#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#include <queue>

#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define Mabs(a,b) ((a)>(b)?(a)-(b):(b)-(a))
#define Abs(a) (a)>0?(a):(-(a))
template <typename QvQ> inline QvQ Min2(QvQ a,QvQ b){if(a<b) return a;return b;}
template <typename QvQ> inline QvQ Max2(QvQ a,QvQ b){if(a>b) return a;return b;}
template <typename QvQ> inline QvQ Abs2(QvQ a){if(a>0) return a;return -a;}

#define inf 0x7f7f7f7f
#define dinf 0x3f3f3f3f
#define llinf 0x7f7f7f7f7f7f7f7f
#define lldinf 0x3f3f3f3f3f3f3f3f

#define ll long long
#define rei register int
#define inv inline void
#define inb inline bool
#define ini inline int
#define inl inline ll

#define bl putchar(' ')
#define ed putchar('\n')
#define test std::cout<<"this:"
#define card system("pause")

#define read2(a,b) read(a),read(b)
#define read3(a,b,c) read(a),read(b),read(c)

#define MAXN 100005
#define MAXM 200005

char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)

template <typename QvQ>inv read(QvQ &x)
{
	x=0;int f=1;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x=x*f;
}
template <typename QvQ>inv write(QvQ x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
using namespace std;
template <typename QvQ>inv exgcd(QvQ a,QvQ b,QvQ &d,QvQ &x,QvQ &y)
{
	if(b==0) {d=a,x=1,y=0;}
	else {exgcd(b,a%b,d,y,x);y-=(a/b)*x;}
}
int n,m[25],a[25];
int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	read(n);int t1,t2,c;
	for(rei i=1;i<=n;++i)
	{
		read3(t1,t2,c);
		int x=0,y=0,g=0;
		exgcd(t1,t2,g,x,y);
		if(c%g==0)
		{
			x*=c/g;
			while(x>0) x-=t2/g;
			while(x<0) x+=t2/g;
			write(x),ed;
		}
		else puts("no");
	}
	return 0;
}
