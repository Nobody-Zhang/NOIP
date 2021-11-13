#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ans=0,f=1;char c=getchar();
	while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return ans*f;
}

void print_(int x)
{
	if(!x) return;
	print_(x/10);
	putchar(x%10+'0');
}

inline void print(int x)
{
	if(!x) putchar('0');
	else print_(x);
	putchar('\n');
}

void exgcd(int a,int b,int &d,int &x,int &y){if(b) exgcd(b,a%b,d,y,x),y-=a/b*x;else x=1,y=0,d=a;}

int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	int a,x,b,c,y,d,n;
	n=read();
	while(n--)
	{
		a=read(),b=read(),c=read();
		exgcd(a,b,d,x,y);
		b/=d;
		if(c%d) puts("no");
		else print((x*1ll*(c/d)%b+b)%b);
	}
}

