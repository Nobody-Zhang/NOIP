#include<bits/stdc++.h>
using namespace std;
int exgcd(int a,int &x,int b,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int xx,yy;
	int gcd=exgcd(b,xx,a%b,yy);
	x=yy;
	y=xx-(a/b)*yy;
	return gcd;
}
int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int a,b,c,x,y;
		scanf("%d%d%d",&a,&b,&c);//ax-by=c
		if(c%gcd(a,-b)!=0) printf("no\n");
		else
		{
			int o=exgcd(a,x,-b,y);
			int p=c/o;
		//	printf("%d %d %d\n!!",x,y,o);
			x=((x*p)%b+b)%b;
			y=((y*p)%b+b)%b;
			//printf("%d %d %d\n",x,y,c);
		printf("%d\n",x);
		}
		
	}
}
