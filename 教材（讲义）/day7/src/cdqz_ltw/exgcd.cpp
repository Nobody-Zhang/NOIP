#include<cstdio>
using namespace std;

int T,aa,bb,cc,op,anss,x,y,ans;

int exgcd (int a,int &x,int b,int &y)
{
	if (b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int xx,yy;
	int gc=exgcd (b,xx,a%b,yy);
	x=yy;
	y=xx-(a/b)*yy;
	return gc;
}

//ax=c+by
//ax-by=c
//ax+(-b)y=c

int main()
{
	freopen ("exgcd.in","r",stdin);
	freopen ("exgcd.out","w",stdout); 
	scanf ("%d",&T);
	for (register int i=1;i<=T;i++)
	{
		scanf ("%d%d%d",&aa,&bb,&cc);
		anss=exgcd (aa,x,bb,y);
		if ((cc%anss)!=0||cc>=bb)
		{
			printf ("no\n");
			continue ;
		}
		ans=x*(cc/anss);
		op=(bb/anss);
		if (ans>0)
		{
			ans%=op;
			printf ("%d\n",ans);
			continue ;
		}
		else
		{
			ans=(ans+op)%op;
			printf ("%d\n",ans);
		}
	}
	return 0;
}
