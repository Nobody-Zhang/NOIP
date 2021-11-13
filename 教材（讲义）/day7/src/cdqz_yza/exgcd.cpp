#include<bits/stdc++.h>
using namespace std;

int T;

int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;y=0;
		return a;
	}
	int gc=exgcd(b,a%b,y,x);
	//b*y+(a-(a/b)*b)*x=gc
	//x*a+(y-(a/b)*x)*b=gc
	y=y-(a/b)*x;
	return gc;
}

int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,x,y;
		scanf("%d%d%d",&a,&b,&c);
		int gc=exgcd(a,b,x,y);
		if(c%gc)
		{
			printf("no\n");
			continue;
		}
		//a*x+b*y = gc
		//dx*a = dy*b = lcm(a,b) = a*b/gcd(a,b)
		//dx = b/gcd(a,b)
		int dx=b/gc;
		int ans=(x*(c/gc)%dx+dx)%dx;
		printf("%d\n",ans);
	}
	return 0;
}
