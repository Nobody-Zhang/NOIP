#include<iostream>
#include<cstdio>
using namespace std;
long long x,y,m,n,l,as,a,b;
long long gcd(long long a,long long b)		
{
	if(a%b==0) return b;
	return gcd(b,a%b);
}
void exgcd(long long a,long long &x,long long b,long long &y)
{
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,x,a%b,y);
	long long yy=y;
	long long xx=x;
	x=yy;
	y=xx-a/b*yy;
	return;
}
int main()
{
	cin>>x>>y>>m>>n>>l;
	as=y-x;
	a=m-n;
	b=l;
	if(a<0)
	{
		a=-a;
		as=-as;
	}
	long long maxx=gcd(a,b);
	if(as%maxx!=0)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	long long k=as/maxx;
	long long A,B;
	exgcd(a,A,b,B);
	cout<<((A*(as/maxx))%(l/maxx)+(l/maxx))%(l/maxx)<<endl;
	return 0;
}
