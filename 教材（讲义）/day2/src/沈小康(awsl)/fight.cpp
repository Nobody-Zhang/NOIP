#include<bits/stdc++.h>
#define N 100001
using namespace std;
typedef long long ll;
int n,m;
ll a[N],p1,s1,s;
ll l,r;
template <class T>
void read(T &x)
{
	char c;int sign=1;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1; x=c-48;
	while((c=getchar())>='0'&&c<='9') x=(x<<1)+(x<<3)+c-48; x*=sign;
}

int main()
{

	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	read(m);read(p1);read(s1);read(s);
	a[p1]+=s1;
	for(int i=1;i<=n;++i)
	{
		if(i<m) l+=(m-i)*a[i];
		if(i>m) r+=(i-m)*a[i];
	}
	ll ans=abs(r-l),p2=m;
	for(int i=1;i<=n;++i)
	{
		if(i<m&&ans>abs(r-l-(m-i)*s)) {ans=abs(r-l-(m-i)*s);p2=i;}
		if(i>m&&ans>abs(r+(i-m)*s-l)) {ans=abs(r+(i-m)*s-l);p2=i;}
	}
	cout<<p2<<endl;
	return 0;
}
