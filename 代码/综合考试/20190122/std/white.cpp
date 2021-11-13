#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100005;
int w[maxn],v[maxn];
int n,L,R;
double seq[maxn];
bool check(double x){
    for(int i=1;i<=n;++i){
        seq[i]=v[i]-x*w[i];
    }
    sort(seq+1,seq+n+1);
    double sum=0;
    for(int i=1;i<=L;++i)sum+=seq[n+1-i];
    return sum>=0.0;
}
int C(int n,int m){//printf("%d %d\n",n,m);
    if(n-m<m)m=n-m;
    long long ans=1;
    for(int i=0;i<m;++i){
        ans=ans*(n-i);//printf("%lld\n",ans);
    }
    for(int i=1;i<=m;++i)ans=ans/i;
    return (int)ans;
}
int calc(double ans){
    for(int i=1;i<=n;++i)seq[i]=v[i]-ans*w[i];
    sort(seq+1,seq+n+1);
    for(int i=1;i<n+1-i;++i)swap(seq[i],seq[n+1-i]);
//    for(int i=1;i<=n;++i)printf("%.7f\n",seq[i]);
    int hi=L,lo=L;
    while(hi<n&&abs(seq[hi]-seq[hi+1])<1e-5)++hi;
    while(lo>1&&abs(seq[lo]-seq[lo-1])<1e-5)--lo;
    //printf("%.5f %.5f\n",ans,seq[L]);
 //   printf("%d %d\n",lo,hi);
    if(abs(seq[L])<1e-5){
        int ans=0;
        for(int i=L;i<=R&&i<=hi;++i)ans+=C(hi,i);
        return ans;
    }else{
        return C(hi-lo+1,L-lo+1);
    }
}
int main(){
    freopen("white.in","r",stdin);
    freopen("white.out","w",stdout);
    scanf("%d%d%d",&n,&L,&R);
    for(int i=1;i<=n;++i)scanf("%d%d",w+i,v+i);
    double l=0.1,r=10;
    while(r-l>1e-6){
        double mid=(l+r)/2.0;
        if(check(mid))l=mid;
        else r=mid;
    }
    printf("%.3f\n",(l+r)/2.0);
    printf("%d\n",calc((l+r)/2.0));
    return 0;
}