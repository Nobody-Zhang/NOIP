#include<stdio.h>
#define INF 10000000007
#define N 500007

struct Node{
	int x;
	long long sum;
}p[N];
int n,d,Q[N]={0};
long long dp[N]={0},k;
template<class T>
inline T max(T x,T y){return x>y? x:y;}
template<class T>
inline void read(T &x){
	x=0;int flag=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') flag=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	x*=flag;
}
inline bool check(int nn){
	int l=max(1,d-nn),r=d+nn;
	for(int i=0;i<=n;i++) Q[i]=0;
	dp[0]=0,p[0].sum=INF;
	int head=1,tail=0,cur=0;
	for(int i=1;i<=n;i++){
		while(p[cur].x<=p[i].x-l){
			while(tail>=head&&dp[cur]>=dp[Q[tail]]) 
				tail--;
			Q[++tail]=cur++;
		}
		while(head<=tail&&p[Q[head]].x<p[i].x-r) head++;
		if(head>tail) dp[i]=-(INF);
		else dp[i]=dp[Q[head]]+p[i].sum;
		if(dp[i]>=k) return false;
	}
	return true;
}
signed main(){
//	freopen("jump.in","r",stdin);
//	freopen("jump.out","w",stdout);
	read(n);read(d);read(k);
	for(int i=1;i<=n;i++)
		read(p[i].x),read(p[i].sum);
	int l=0,r=p[n].x;
	while(l<r){
		int mid=(r+l)>>1;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	if(!check(l)) printf("%d",l);
	else printf("-1");
}
/*
7 4 10
2 6
5 -3
10 3
11 -3
13 1
17 6
20 2

10 59 112
41 27
89 -50
112 -4
144 -45
187 42
196 35
237 8
262 2
269 -8
273 -37


*/
