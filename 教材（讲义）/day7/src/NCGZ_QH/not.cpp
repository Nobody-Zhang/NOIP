#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
//#include<vector>
#include<stack>
//#include<map>
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
#define Pause system("pause")
using namespace std;
const int N=100005;
Ii read(){
    int s=0,f=1;char c;
    for(c=getchar();c>'9'||c<'0';c=getchar())if(c=='-')f=-1;
    while(c>='0'&&c<='9')s=s*10+(c^'0'),c=getchar();
    return s*f;
}
template<class Tp>Iv print(Tp x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10^'0');
}
int n,m,a[105];ll ans;
Ii gcd(int a,int b){
	while(b^=a^=b^=a%=b);return a;
	//return !b?a:gcd(b,a%b);
}
Iv dfs(int x,int cnt,int tot){
	if(cnt&1)ans+=m/tot;
	else ans-=m/tot;
	R(i,x+1,n)
		dfs(i,cnt+1,tot*a[i]/gcd(tot,a[i]));
}
#define ON_JUD
int main(){
#ifdef ON_JUD
	freopen("not.in","r",stdin),freopen("not.out","w",stdout);
#endif
	n=read(),m=read();
	R(i,1,n)
		a[i]=read();
	R(i,1,n)
		dfs(i,1,a[i]);
	print(m-ans);
	return 0;
}
/*
3 20
2 3 5
*/
