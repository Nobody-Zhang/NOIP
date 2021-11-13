#include<stdio.h>
int a,b,x,y,c;

inline int exgcd(int a,int b,int &xx,int &yy){
	if(b==0){
		xx=1;yy=0;
		return a;
	}
	int rest=exgcd(b,a%b,xx,yy);
	int tmp=xx;
	xx=yy;
	yy=tmp-a/b*yy;
	return rest;
}
inline bool check(int u){
	int ans=exgcd(a,b,x,y);
	if(c%ans) return false;
	int k=c/ans;
	x*=k;y*=k;
	int t=b/ans;
	x=(x%t+t)%t;
	return true;
}
int main(){
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&c);
		if(check(c)) printf("%d\n",x);
		else printf("no\n");
	}
}
