#include<stdio.h>
#define N 100007
#define ll long long

int n,p1,m;
ll sum[N],sum1,sum2,s1,s2,a[N];

inline ll abss(ll a){if(a<0) return (-a);else return a;}
template<class T>
inline void read(T &x){
	x=0;int flag=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') flag=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	x*=flag;
}
signed main(){
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	read(m);read(p1);read(s1);read(s2);
	a[p1]+=s1;
	for(int i=1;i<=n;i++)
		if(i<m) sum1+=(m-i)*a[i];
		else if(i>m) sum2+=(i-m)*a[i];
	if(sum1==sum2){
		printf("%d",m);
		return 0;
	}
	int pos=m;
	ll d=abss(sum1-sum2);
	for(int i=1;i<=n;i++)
		if(i<m){
			sum1+=(m-i)*s2;
			ll rest=abss(sum1-sum2);
			if(rest<d){
				pos=i;
				d=rest;
			}
			sum1-=(m-i)*s2;
		}
		else if(i>m){
			sum2+=(i-m)*s2;
			ll rest=abss(sum1-sum2);
			if(rest<d){
				pos=i;
				d=rest;
			}
			sum2-=(i-m)*s2;
		}
	printf("%d",pos);
}
