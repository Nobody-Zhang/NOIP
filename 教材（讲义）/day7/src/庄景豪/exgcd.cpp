#include<bits/stdc++.h>
#define LL long long 
using namespace std;

inline LL exgcd(LL a,LL b,LL &x,LL &y){
	if(b==0){
		x=1;y=0;
		return a;
	}
	LL gc;
	LL xx,yy;
	gc=exgcd(b,a%b,xx,yy);
	x=yy;
	y=xx-a/b*yy;
	return gc;
}
LL a,b,c,gc;
int t;
int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		LL x,y;
		scanf("%lld%lld%lld",&a,&b,&c);
		gc=exgcd(a,b,x,y);
		if(c%gc){
			printf("no\n");
			continue;
		}
		int lmc=b/gc;
		printf("%lld\n",((x*(c/gc)%lmc)+lmc)%lmc);
	}
}
