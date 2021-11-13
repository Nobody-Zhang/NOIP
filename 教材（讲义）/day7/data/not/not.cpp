#include<cstdio>
typedef long long ll;
const int maxn=1<<10;
int cnt1[maxn];
int LCM[maxn];
int gcd(int a,int b){
    return (b==0)?a:gcd(b,a%b);
}
ll lcm(ll a,ll b){
    if(a==-1||b==-1)return -1;
    return a/gcd(a,b)*b;
}
int a[10];
int n,m;
int lb(int x){
    return x&(-x);
}
int main(){
    cnt1[0]=0;
    for(int i=1;i<maxn;++i)cnt1[i]=cnt1[i>>1]+(i&1);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%d",a+i);
    LCM[0]=1;
    for(int i=0;i<n;++i)LCM[1<<i]=a[i];
    for(int i=1;i<(1<<n);++i){
        if(i!=lb(i)){
        	ll x=lcm(LCM[i-lb(i)],LCM[lb(i)]);
            LCM[i]=(x>m)?-1:x;
        }
    }
    ll ans=0;
    for(int i=0;i<(1<<n);++i){
        if(LCM[i]==-1)continue;
        if(cnt1[i]&1){
            ans-=m/LCM[i];
        }else{
            ans+=m/LCM[i];
        }
    }
    printf("%d\n",(int)(ans));
    return 0;
}
