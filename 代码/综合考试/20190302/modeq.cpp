#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
bool flag1,flag2;
long long a,b,c,x,y,n;
long long exgcd(long long a,long long b)
{
	if(b==0){
		x=1,y=0;return a;
	}
	long long gc=exgcd(b,a%b);
	long long xx=y;
	long long yy=x-a/b*y;
	x=xx;
	y=yy;
	return gc;
}
int main()
{
	//freopen("modeq.in","r",stdin);
	//freopen("modeq.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a<0) flag1=true;
		if(b<0) flag2=true;
		int gc=exgcd(abs(a),abs(b));
		if(c%abs(gc)){
			printf("No\n");
			flag1=false;
			flag2=false;
			continue;
		}
		long long best=c/gc;
		a/=abs(gc);
		b/=abs(gc);
		x*=best;y*=best;
		if(flag2)
		{
			
			while(x>=0)
			{
				x+=b;
				y-=a;
			}
			while(x<0)
			{
				y+=a;
				x-=b;
			}
		}
		else{
			while(x>=0)
			{
				x-=b;
				y+=a;
			}
			while(x<0)
			{
				y-=a;
				x+=b;
			}
		}
		cout<<x<<" "<<y<<" ";
		if(flag1)
		{
			while(y>=0)
			{
				y+=a;
				x-=b;
			}
			while(y<0)
			{
				y-=a;
				x+=b;
			}
		}
		else{
			while(y>=0)
			{
				y-=a;
				x+=b;
			}
			while(y<0)
			{
				y+=a;
				x-=b;
			}
		}
		cout<<x<<" "<<y<<endl;
		flag1=false;
		flag2=false;
	}
	return 0;
}
