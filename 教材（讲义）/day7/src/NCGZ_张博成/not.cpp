#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#include <bitset>

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
bitset <200000001> vis;
int a[11];
ini gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
ini lcm(int a,int b){return a*b/gcd(a,b);}
int main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	int n,m;
	read2(n,m);int ans=0;
	for(rei i=1;i<=n;++i) read(a[i]);
	if(n==1)
	{
		write(m-m/a[1]);
		return 0;
	}
	if(n==2)
	{
		int lcm=a[1]*a[2]/gcd(a[1],a[2]);
		write(m-(m/a[1])-(m/a[2])+(m/lcm));
		return 0;
	}
	if(n==3)
	{
		int lcm1=lcm(a[1],a[2]);
		int lcm2=lcm(a[2],a[3]);
		int lcm3=lcm(a[1],a[3]);
		int totlcm=lcm(lcm1,a[3]);
		int minnus=m/a[1]+m/a[2]+m/a[3]-m/lcm1-m/lcm2-m/lcm3+m/totlcm;
		write(m-minnus);return 0;
	}
	for(rei i=1;i<=n;++i)
	{
		for(rei j=a[i];j<=m;j+=a[i])
		{
			if(!vis[j]) vis[j]=1,++ans;
		}
	}
	write(m-ans);
	return 0;
}
