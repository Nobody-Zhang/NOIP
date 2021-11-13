#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
//#include<vector>
//#include<stack>
#include<map>
#define R(a,b,c) for(register int (a)=(b);(a)<=(c);++(a))
#define nR(a,b,c) for(register int (a)=(b);(a)>=(c);--(a))
#define Ii inline int
#define Iv inline void
#define Il inline long long
#define Ib inline bool
#define INF 0x7ffffff
#define re register
#define ll long long
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define Cmin(a,b) ((a)=(a)<(b)?(a):(b))
#define Cmax(a,b) ((a)=(a)>(b)?(a):(b))
#define Fill(a,b) memset((a),(b),sizeof((a)))
#define D_e_Line printf("\n-------------\n");
#define D_e(x) printf("\n______%d_______\n",x)
#define Pause() system("pause")
#define int long long
using namespace std;
const int N=100005;
Il read(){
    ll s=0,f=1;char c;
    for(c=getchar();c>'9'||c<'0';c=getchar())if(c=='-')f=-1;
    while(c>='0'&&c<='9')s=s*10+(c^'0'),c=getchar();
    return s*f;
}
template<class Tp>Iv print(Tp x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10^'0');
}
ll x,y,d,a,b,c;
Iv Exgcd(ll a,ll b,ll &x,ll &y,ll &d){
	if(!b)
		x=1,y=0,d=a;
	else
		Exgcd(b,a%b,y,x,d),y-=x*a/b;
}
#define ON_JUD
signed main(){
#ifdef ON_JUD
	freopen("exgcd.in","r",stdin),freopen("exgcd.out","w",stdout);
#endif
	int T=read();
	while(T--){
		a=read(),b=read(),c=read(),
		Exgcd(a,b,x,y,d);
		b/=d;
		if(c%d!=0){
			printf("no\n");continue;
		}
		printf("%I64d\n",(x*1ll*c/d%b+b)%b);
	}
	return 0;
}
/*
9
7 9 6
1 2 1
2 6 5
2 3 2
4 5 4
2 3 2
1 5 2
4 5 3
2 4 2

6
1
no
1
1
1
2
2
1
*/
