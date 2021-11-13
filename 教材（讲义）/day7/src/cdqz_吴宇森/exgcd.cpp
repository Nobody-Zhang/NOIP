#include<bits/stdc++.h>
using namespace std;

int T;

long long exgcd(long long a,long long b,long long &x,long long &y) 
{
	if(!b) 
	{
		x=1,y=0;
		return a;
	} 
	else 
	{
		long long xx,yy,gcd=exgcd(b,a%b,xx,yy);
		x=yy,y=xx-a/b*yy;
		return gcd ;
	}
}

int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		long long a,b,c,x,y;
		scanf("%I64d%I64d%I64d",&a,&b,&c);
		long long t=exgcd(a,b,x,y);
		if(c%t)
		{
			printf("no\n");
		}
		else
		{
			long long dx=(a*b)/t/a;
			long long xx=c/t*x;
			printf("%I64d\n",(xx%dx+dx)%dx);
		}
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
