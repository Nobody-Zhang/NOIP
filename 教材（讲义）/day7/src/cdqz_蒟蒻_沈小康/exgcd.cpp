#include<bits/stdc++.h>
using namespace std;
int t;
int a,b,c,d;

template <class T>
void read(T &x)
{
	char c;int sign=1;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1; x=c-48;
	while((c=getchar())<='9'&&c>='0') x=x*10+c-48; x*=sign;
}

int exgcd(int a,int b,int &x,int &y)
{
	if(!b) {x=1;y=0;return a;}
	int d=exgcd(b,a%b,x,y);
	int t=x;x=y;y=t-a/b*y;
	return d;
}

int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	read(t);
	while(t--)
	{
		read(a);read(b);read(c);
		int x,y;
		d=exgcd(a,b,x,y);
		if(c%d) cout<<"no"<<endl;
		else cout<<(x*c/d%(b/d)+(b/d))%(b/d)<<endl;
	}
	return 0;
}
