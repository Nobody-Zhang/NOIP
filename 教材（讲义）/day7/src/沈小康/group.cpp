#include<bits/stdc++.h>
#define N 2000005
using namespace std;
typedef long long ll;
int n,k;
int p[N],q[N],head=1,tail=0;
ll a,f[N],sum[N];

template <class T>
void read(T &x)
{
	char c;int sign=1;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1; x=c-48;
	while((c=getchar())>='0'&&c<='9') x=(x<<1)+(x<<3)+c-48; x*=sign;
}

int main()
{
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	read(n);read(k);
	f[0]=0;
	for(int i=1;i<=n;++i)
	{
		read(a);sum[i]=sum[i-1]+a;
		ll val=f[i-1]-sum[i];
		while(head<=tail&&val>=f[q[tail]-1]-sum[q[tail]]) tail--;
		q[++tail]=i;
		while(head<=tail&&q[head]<i-k) head++;
		if(i>k)f[i]=f[q[head]-1]-sum[q[head]]+sum[i];
		else f[i]=sum[i];
	}
	cout<<f[n]<<endl;
	return 0;
}
/*
5 2
1 2 3 4 5
*/
