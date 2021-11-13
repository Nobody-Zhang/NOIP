#include <cstdio>
using namespace std;
long long abs (long long x,long long y) {
    if(x >= y) return x - y;
    return y - x;
}
long long m,p1,s1,s2,a[1000005];
int n;
int main () {
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
    long long min=1e19,where;
    long long sum1=0,sum2=0;
    long long t1,t2;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    scanf("%lld%lld%lld%lld",&m,&p1,&s1,&s2);
 	a[p1] += s1;
    for(int i=1;i<=n;i++) {
        if(i<m)sum1+=(m-i)*a[i];
        else if(i>m)sum2+=(i-m)*a[i];
    }
    for(int i=1;i<=n;i++) {
        t1=sum1;
        t2 =sum2;
        if(i<m)t1+=(m-i)*s2;
        else if(i > m) t2+=(i-m)*s2;
        long long tmp =abs(t1,t2);
        if(min>tmp) {
            min=tmp;
            where=i;
        }
    }
    printf("%lld", where);
    return 0;
}
/*
6
2 3 2 3 2 3
4 6 5 2

2
*/
