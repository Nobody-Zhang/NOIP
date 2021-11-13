#include<bits/stdc++.h>
using namespace std;
long long a,b,c,x,y,g;
long long work,t;
long long Exgcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	else
	{
		long long xx,yy;
 		g=Exgcd(b,a%b,xx,yy);
		x=yy;
		y=xx-a/b*yy;
		return g;
	}
}
int T;
int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		work=Exgcd(a,b,x,y);
		if(c%work)
		{
			printf("no\n");
		}
		else
		{
			int l=b/work;
			cout<<(x*c/work%l+l)%(l)<<endl;
		}
	}
	return 0;
}
