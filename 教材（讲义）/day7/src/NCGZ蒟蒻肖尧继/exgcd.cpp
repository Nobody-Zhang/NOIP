#include<cstdio>
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
long long x,y;
int Gcd;
inline void exgcd(int a,int b,long long &x,long long &y,int &Gcd)
{
	if(!b)x=1,y=0,Gcd=a;
	else
	{
		exgcd(b,a%b,y,x,Gcd);
		y-=x*a/b;
	}
}
int T;
int a,b,c;
int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	read(T);
	while(T--)
	{
		read(a),read(b),read(c);
		exgcd(a,b,x,y,Gcd);
		b/=Gcd;
		if(c%Gcd!=0)puts("no");
		else print((x*(c/Gcd)%b+b)%b),putchar('\n');
	}
	return 0;
}
/*
9
7 9 6
1 2 1
2 6 5
2 3 2
4 5 4
2 3 2
1 5 2
4 5 3
2 4 2
*/
