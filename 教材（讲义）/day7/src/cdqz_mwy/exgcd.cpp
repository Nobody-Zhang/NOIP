#include<bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0) { x=1; y=0; return a; }
	int d=exgcd(b,a%b,y,x);
	y=y-(a/b)*x;
	return d;
}
int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	int n,a,b,c;
	scanf("%d",&n);
	while(n--)
	{
		int x,y,flag=0,m;
		scanf("%d%d%d",&a,&b,&c);
		int d=exgcd(a,b,x,y);
		if(c%d==0) 
		{
			x=(x%b+b)%b;
			printf("%d\n",x);
		}
		else printf("no\n");
	}
}
/*
9
7 9 6//
1 2 1
2 6 5//
2 3 2
4 5 4
2 3 2
1 5 2
4 5 3
2 4 2//
*/
