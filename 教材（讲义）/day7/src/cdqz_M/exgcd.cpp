#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
template<class T> void read(T &re);

int exgcd(int a,int &x,int b,int &y)
{
	if(b==0) {x=1;y=0;return a;}
	int xx,yy;
	int re=exgcd(b,xx,a%b,yy);
	x=yy;
	y=xx-(a/b)*yy;
	return re;
}

int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	int T;read(T);
	while(T--){
		int a,x,b,y,c;
		read(a);read(b);read(c);
		int g=exgcd(a,x,b,y);
		if(c%g||c>b){
			printf("no\n");
			continue;
		}else{
			int ans=x*(c/g),B=b/g;
			ans=(ans+B)%B;
			printf("%d\n",ans);
		}
	}
	return 0;
}

template<class T> void read(T &re)
{
	re=0;
	T sign=1;
	char tmp;
	while((tmp=getchar())&&(tmp<'0'||tmp>'9')) if(tmp=='-') sign=-1;
	re=tmp-'0';
	while((tmp=getchar())&&(tmp>='0'&&tmp<='9')) re=re*10+(tmp-'0');
	re*=sign;
}