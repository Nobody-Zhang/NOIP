#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(a%b==0) return b;
	return gcd(b,a%b);
}
void exgcd(int a,int &x,int b,int &y)
{
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,x,a%b,y);
	int yy=y;
	int xx=x;
	x=yy;
	y=xx-a/b*yy;
	return;
}
int main()
{
	int a,b,x,y,as,maxx,k;
	cin>>a>>b>>as;
	if(a>b)maxx=gcd(a,b);
	else maxx=gcd(b,a);
	if(as%maxx==0){
		k=as/maxx;
	}
	else return 0;
	exgcd(a,x,b,y);
	cout<<x*k<<" "<<y*k<<endl;
	return 0;
}
