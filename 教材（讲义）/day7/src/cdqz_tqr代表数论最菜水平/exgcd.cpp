#include<bits/stdc++.h>
#define _ 0
using namespace std;

int x,y,xx,yy,a,b,c;

int exgcd(int a,int b,int &x,int &y)
{
	if (b==0) {x=1;y=0;return a;}
	int n=exgcd(b,a%b,x,y);
	int xx=x,yy=y;
	x=yy;
	y=xx-a/b*yy;
	return n;
}

template<class T>inline void read(T &res)
{
	static char ch;T flag=1;
	while((ch=getchar())<'0'||ch>'9')if(ch=='-')flag=-1;res=ch-48;
	while((ch=getchar())>='0'&&ch<='9')res=res*10+ch-48;res*=flag;
}

int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	int T;read(T);
	while (T--)
	{		
		read(a);read(b);read(c);
		int g=exgcd(a,b,x,y);
		if(c%g||c>b) {printf("no\n");continue;}
		// x=x*c/g;
		// y=y*c/g;
		//已求出a*x+b*y=c
		//a*x-b*y=c
		//a*x=c+b*y
		//x=(c+b*y)/a
		// printf("%d*%d-%d*%d=%d\n\n",a,x,b,y,c);
		// int ans=x*c/g,B=b/g;
		// ans=(ans+B)%B;
		// printf("%d\n",ans);
		int ans=x*(c/g),B=b/g;
		ans=(ans+B)%B;
		printf("%d\n",ans);
		// cout<<a<<endl<<x<<endl<<b<<endl<<y<<endl<<c;
	}
	return (0^_^0);
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

6
1
no
1
1
1
2
2
1
 */