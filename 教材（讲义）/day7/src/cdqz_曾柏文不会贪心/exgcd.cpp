#include<bits/stdc++.h>
using namespace std;
long long T,a,b,c,n,x;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	} 
	long long xx,yy,d=exgcd(b,a%b,xx,yy);
	x=yy;
	y=xx-a/b*yy;
	return d ;
}
int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	scanf("%I64d",&T);
	for(int tim=1;tim<=T;tim++)
	{
		scanf("%I64d%I64d%I64d",&a,&b,&c);
		int gcd=exgcd(a,b,x,n);
		if(c%gcd!=0) {printf("no\n");continue;}
		printf("%I64d\n",(x*c/gcd+b)%b);
	}
	return 0;
}
