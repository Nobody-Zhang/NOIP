#include<bits/stdc++.h>
using namespace std;
int t,aa,bb,cc,X;
int exgcd(int a,int b,int &x,int &y) 
{
	if(b==0) 
	{
	 x=1; 
	 y=0; 
	 return a; 
	}
	int gc=exgcd(b,a%b,x,y);
	int z=x;
	x=y;
	y=z-y*(a/b);
	return gc; 
}
int baoli(int a,int b,int c)
{
	for(int i=1;i<=1000000;i++)
	{
		if(a*i%b==c)
		return i;
	}
}
int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	int i,x;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d%d",&aa,&bb,&cc);
		if(aa<1000000)
		{
			x=baoli(aa,bb,cc);
			if(x<=0)
			cout<<"no"<<endl;
			else
			cout<<x<<endl;
		}
		else
		cout<<exgcd(aa%bb,0,cc,x);
	}
	return 0;
}
