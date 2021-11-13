#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int x,y,a,b,c,d;
int exgcd(int a,int b)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b),t;
    t=x;x=y;y=t-a/b*y;
    return d;
}
int t;
int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	scanf("%d",&t);
	for(register int i=1;i<=t;++i)
	{
		x=y=0;
		scanf("%d%d%d",&a,&b,&c);
		d=exgcd(a,b);
		if(c%d!=0)puts("no");
		else{
			x=x*c/d%(b/d);
			if(x<0) x+=abs(b/d);
			printf("%d\n",x);
		}
		
	}
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
