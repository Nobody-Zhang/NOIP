#include<bits/stdc++.h>
using namespace std;

int t;

int exgcd(int a,int &x,int b,int &y){
	if(!b){
		x=1;y=0;
		return a;
	}
	int xx,yy;
	int gc=exgcd(b,xx,a%b,yy);
	x=yy;
	y=xx-(a/b)*yy;
	return gc;
}

int main(){
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int x,y;
		int gc=exgcd(a,x,b,y);
		//printf("%d ",gc);
		//printf("%d %d",x,y);
		if(c%gc!=0)  printf("no\n");
		else {
			x=x*c/gc;
			x=(x%(b/gc)+b/gc)%(b/gc);
			printf("%d\n",x);
		}
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
