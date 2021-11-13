#include<cstdio>
#include<cassert>
int gcd(int a,int b){
    return (b==0)?a:gcd(b,a%b);
}
int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    int g=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return g;
}
void work(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    assert(0<a&&0<b&&0<c&&a<100000000&&b<100000000&&c<100000000&&c<b&&a<b);
    int g=gcd(a,b);
    if(c%g!=0)printf("no\n");
    else{
        int x,y;
        exgcd(a,b,x,y);
        //printf("%d %d %d %d\n",a,b,x,y);
        //lcm(a,b)=a*b/g
        //x += lcm(a,b)/a y-=lcm(a,b)/b 
        //x<0?x>0?
        int dlt=b/g;
        int ans=(x*1ll*(c/g)%dlt+dlt)%dlt;
        if(ans==0)ans+=dlt;
        printf("%d\n",ans);
    }
}
int main(){
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
    int T;
    scanf("%d",&T);assert(T<=10);
    while(T--){
        work();
    }
    return 0;
}
