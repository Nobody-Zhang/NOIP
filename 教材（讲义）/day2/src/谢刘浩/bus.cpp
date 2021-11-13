#include<stdio.h>
#include<math.h>
#include<algorithm>
#define maxn 4000105
using namespace std;

int n,m,t,ti,ans=1e9;
int cnt[maxn],sum[maxn],f[maxn];
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ti);t=max(t,ti);
        cnt[ti]++;sum[ti]+=ti;
    }
    for(int i=1;i<t+m;i++){cnt[i]+=cnt[i-1];sum[i]+=sum[i-1];}
    for(int i=0;i<t+m;i++){
        if(i>=m&&cnt[i-m]==cnt[i])
		{f[i]=f[i-m];continue;}
        f[i]=cnt[i]*i-sum[i];
        for(int j=max(i-m-m+1,0);j<=i-m;j++)
		{f[i]=min(f[i],f[j]+(cnt[i]-cnt[j])*i-(sum[i]-sum[j]));}
    }
    for(int i=t;i<t+m;i++){ans=min(ans,f[i]);}
    printf("%d\n",ans);
    return 0;
}
