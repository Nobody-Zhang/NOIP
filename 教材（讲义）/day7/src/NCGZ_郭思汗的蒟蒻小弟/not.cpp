#include<cstdio>
using namespace std;
#define rg register int
#define ll long long
#define V inline void
#define I inline int
#define F1(i,a,b) for(rg i=a;i<=b;++i)
#define bl putchar(' ')
#define ed putchar('\n')
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
const int N=15;
template<typename TP>V read(TP &x)
{
	TP f=1;x=0;register char c=getchar();
	for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c^'0');
	x*=f;
}
template<typename TP>V print(TP x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) print(x/10);
	putchar(x%10+'0'); 
}
int n,a[N],m,cnt;
template<typename TP>I gcd1(TP a,TP b) {return !b?a:gcd1(b,a%b);}
template<typename TP>inline ll lcm(TP a,TP b) {return (ll)1ll*(a*b)/(1ll*gcd1(a,b));}
I calc()
{
	ll ans=1ll;
	F1(i,2,n)
	{
		ans*=(ll)lcm(a[i],a[i-1]);
		if(ans>m) return (m+1);
	}
	return ans;
}
int main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	read(n),read(m),cnt=m;
	F1(i,1,n) read(a[i]),cnt-=(m-m/a[i]);
	cnt-=(m-m/calc());
	cnt+=(m-m/(a[1]*a[n]));
	F1(i,2,n) cnt+=(m-m/(a[i]*a[i-1]));
	print(m-cnt);
	return 0;
}
/*
4 78
3 5 11 7
26 15 7 11
33
*/
