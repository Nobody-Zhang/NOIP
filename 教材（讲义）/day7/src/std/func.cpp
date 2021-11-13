#include<cstdio>
const int maxn=100005;
int prime[maxn],tot;
bool no[maxn];
int g[maxn],mf[maxn];//mf[i]:minimum factor of i
void linear(){
    mf[1]=1;g[1]=1;
    for(int i=2;i<maxn;++i){
        if(!no[i]){
            prime[++tot]=i;
            g[i]=mf[i]=i;
        }
        for(int j=1;j<=tot&&prime[j]*i<maxn;++j){
            no[prime[j]*i]=true;
            mf[prime[j]*i]=prime[j];
            g[prime[j]*i]=g[i]+(mf[i]!=prime[j])*prime[j];
            if(i%prime[j]==0)break;
        }
    }
}
int phi(int x){
    int ans=x;
    for(int i=2;i*i<=x;++i){
        if(x%i==0){
            ans=ans/i*(i-1);
            while(x%i==0)x/=i;
        }
    }
    if(x!=1)ans=ans/x*(x-1);
    return ans;
}
int qpow(int a,int x,int m){
    int ans=1;
    for(;x;x>>=1,a=a*1ll*a%m)if(x&1)ans=ans*1ll*a%m;
    return ans;
}
int main(){
    freopen("func.in","r",stdin);
    freopen("func.out","w",stdout);
    linear();
    int L,R,D;scanf("%d%d%d",&L,&R,&D);
    int ph=phi(D);
    int ans=0;
    for(int i=L;i<=R;++i)ans=ans^qpow(2048,qpow(3,g[i],ph),D);
    printf("%d\n",ans);
    return 0;
}