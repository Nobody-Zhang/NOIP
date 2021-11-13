#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#include <queue>
#include <cmath>

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
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)

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
int mod;
template <typename QvQ>QvQ qpow(QvQ x,QvQ y)
{
	if(y==0) return 1;
	QvQ ret=1;
	while(y)
	{
		if(y&1) ret=ret*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ret%mod;
}
int F(int x)
{
	int sum=0;if(x==1) sum=1;
	for(rei i=2;i*i<=x;++i)
	 if(x%i==0){sum+=i;while(x%i==0) x/=i;}
	if(x>1) sum+=x;
	int pp=pow(3,sum);
	return qpow(2048,pp);
}
int main()
{
	freopen("func.in","r",stdin);
	freopen("func.out","w",stdout);
	int L,R;
	read3(L,R,mod);
	int ans=F(L);
	for(rei i=L+1;i<=R;++i) ans^=F(i);
	write(ans);
	return 0;
}
