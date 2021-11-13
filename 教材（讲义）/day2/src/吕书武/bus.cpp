#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 503

int n,m,a[N],f[N][N];
inline int min(int x,int y){return x<y? x:y;}
template<class T>
inline void read(T &x){
	x=0;int flag=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')flag=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	x*=flag;
}
inline int dfs(int step,int st){
	if(step==n+1) return 0;
	if(st<a[step]) return dfs(step,a[step]);
	if(f[step][st-a[step]]!=-1) return f[step][st-a[step]];
	int sum=0,i=step;
	while(i<=n&&a[i]<=st)
		sum+=a[i++];
	int rest=(i-step)*st-sum+dfs(i,st+m);
	while(i<=n){
		sum+=a[i];
		rest=min(rest,(i-step+1)*a[i]-sum+dfs(i+1,a[i]+m));
		i++;
	}
	return f[step][st-a[step]]=rest;
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			f[i][j]=-1;
	sort(a+1,a+1+n);
	printf("%d",dfs(1,0));
}
