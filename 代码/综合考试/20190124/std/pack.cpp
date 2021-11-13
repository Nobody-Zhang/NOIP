#include<cstdio>
#include<cassert>
int n,m;
int w[505],v[505];
long long sumw[1<<20],sumv[1<<20];
void work1(){
    assert(n<=20&&m<=1000000000);
    for(int i=1;i<=n;++i)assert(w[i]<=1000000000&&v[i]<=1000000000);
    for(int i=0;i<n;++i){
        sumw[1<<i]=w[i+1];
        sumv[1<<i]=v[i+1];
    }
    long long ans=0;
    for(int i=0;i<(1<<20);++i){
        int lowbit=i&(-i);
        sumw[i]=sumw[lowbit]+sumw[i^lowbit];
        sumv[i]=sumv[lowbit]+sumv[i^lowbit];
        if(sumw[i]<=m&&sumv[i]>ans)ans=sumv[i];
    }
    printf("%I64d\n",ans);
}
long long f[5005];
void work2(){
    assert(n<=500&&m<=500);
    for(int i=1;i<=n;++i)assert(w[i]<=1000000000&&v[i]<=1000000000); 
    for(int i=0;i<=m;++i)f[i]=0;
    for(int i=1;i<=n;++i){
        for(int j=m;j>=w[i];--j){
            if(f[j-w[i]]+v[i]>f[j])f[j]=f[j-w[i]]+v[i];
        }
    }
    printf("%I64d\n",f[m]);
}
void work3(){
    assert(n<=500&&m<=1000000000);
    for(int i=1;i<=n;++i)assert(w[i]<=1000000000&&v[i]<=10);
    int sum=0;
    for(int i=1;i<=n;++i)sum+=v[i];
    for(int i=1;i<=sum;++i)f[i]=1ll<<60;
    for(int i=1;i<=n;++i){
         for(int j=sum;j>=v[i];--j){
             if(f[j-v[i]]+w[i]<f[j])f[j]=f[j-v[i]]+w[i];
         }
    }
    int ans=0;
    while(f[ans+1]<=m)++ans;
    printf("%d\n",ans);
}
int main(){
    freopen("pack.in","r",stdin);
    freopen("pack.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d%d",&w[i],&v[i]);
    if(n<=20)work1();
    else if(m<=500)work2();
    else work3();
    return 0;
}
