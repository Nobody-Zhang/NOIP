#include<bits/stdc++.h>
using namespace std;
#define m 21252
int tot;
void exgcd(int a,int &x,int b,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,x,a%b,y);
	int xx=x;
	int yy=y;
	x=yy;
	y=xx-a/b*yy;
	return;
}
void solve(int m1,int m2,int m3,int from)
{
	int t1,t2,t3,k;
	exgcd(m/23,t1,23,k);
	exgcd(m/28,t2,28,k);
	exgcd(m/33,t3,33,k);
	t1=((t1%23)+23)%23;
	t2=((t2%28)+28)%28;
	t3=((t3%33)+33)%33;//ÇóÄæÔª 
	long long ans=0;
	ans+=m1*(m/23)*t1;
	ans+=m2*(m/28)*t2;
	ans+=m3*(m/33)*t3;
	ans%=m;
	if(ans-from==0)
	{
		cout<<m;
		return;
	}
	cout<<((ans-from)+m)%m;
	return;
}
int main()
{
	while(1)
	{
		tot++;
		int a,b,c,from;
		cin>>a>>b>>c>>from;
		if(a==-1&&b==-1&&c==-1&&from==-1) return 0;
		cout<<"Case "<<tot<<": the next triple peak occurs in ";
		solve(a,b,c,from);
		cout<<" days."<<endl;
	}
}
