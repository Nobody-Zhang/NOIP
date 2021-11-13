#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	else gcd(b,a%b); 
}

int exgcd(int a,int &x,int &d,int b,int &y)
{
	int t;
	if(b==0)
	{
		d=a;
		x=1,y=0;
		return a;
	}
	int g=exgcd(b,x,d,a%b,y);
	t=x;
	x=y;
	y=t-y*a/b;
}

int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	int t,x,y;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int m=gcd(a,b);
		exgcd(a,x,m,b,y);
		if(c%m==0)
		{
			x=x*c/m;
			x=(x%(b/m)+(b/m))%(b/m);
			printf("%d\n",x);	
		}  
		else printf("no\n");
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
/*
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

