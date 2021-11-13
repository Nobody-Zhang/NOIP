#include<bits/stdc++.h>
using namespace std;
int T;
int exgcd(int a,int &x,int b,int &y)
{
	if(b==0){ x=1; y=0; return a; }
	int xx,yy,gcd=exgcd(b,xx,a%b,yy);
	x=yy;
	y=xx-a/b*yy;
	return gcd;
}
int gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}
int read()
{
	int x=0,f=1; char s=getchar();
	while(s<'0'||s>'9'){ if(s=='-') f=-1; s=getchar();}
	while(s>='0'&&s<='9'){ x=x*10+s-'0'; s=getchar();}
	return x*f;
}
int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	T=read();
	while(T--)
	{ 
	    int a,b,c,x,y;
		a=read(),b=read(),c=read();
		int d=exgcd(a,x,b,y);
		int f=gcd(a,b);
        if(c%f==0)
        {
        	x=(x%b+b)%b;
        	printf("%d\n",x);
        }
        else printf("no\n");
	//	printf("%d %d %d %d=%d\n",a,x,b,y,d);
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
