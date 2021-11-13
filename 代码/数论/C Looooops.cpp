#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
long long mod;
void mi(int k)
{
	mod=1;
	int base=2;
	while(k)
	{
		if(k&1) mod*=base;
		base*=base;
		k>>=1;
	}
	return;//ok
}
long long gcd(long long a,long long b)
{
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
void exgcd(long long a,long long &x,long long b,
long long &y)
{//ax+by==ans
	if(b==0)
	{
		x=1,y=0;
		return;
	} 
	exgcd(b,x,a%b,y);
	long long xx,yy;
	xx=y;
	yy=x-a/b*y;
	x=xx;
	y=yy;
	return;
}
void solve(int a,int c)
{
	long long maxx=gcd(a,mod);
	if(c%maxx!=0)
	{
		cout<<"FOREVER"<<endl;
		return;
	}
	long long k=c/maxx;
	long long x,y;
	exgcd(a,x,mod,y);
	cout<<(((x*k)%(mod/maxx)+(mod/maxx))%(mod/maxx))<<endl;
	return;
}
int main()
{
	while(1)
	{
		int a,b,c,k;
		cin>>a>>b>>c>>k;
		if(a==0&&b==0&&c==0&&k==0) {
			cout<<"FOREVER"<<endl;
			return 0;
		}
		mi(k);
		solve(c,b-a);
	}
} 
