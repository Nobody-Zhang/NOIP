#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2000200;
template <class T> inline void read(T &x)
{
	char ch;
	while((ch=getchar())<'0'||ch>'9');
	x=ch-48;
	while((ch=getchar())>='0'&&ch<='9')
	x=x*10+ch-48;
}
inline int max(int a,int b){
	return a>b?a:b;
}
int n,k,a[maxn];
ll dp[maxn][2],sum[maxn],q[maxn];
int main()
{
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	read(n);read(k);
	for(int i=1;i<=n;i++){
		read(a[i]);sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=1;
	for(int i=1;i<=n;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		while(q[l]<i-k&&l<=r)l++;
		dp[i][1]=dp[q[l]][0]-sum[q[l]]+sum[i];
		while(dp[i][0]-sum[i]>dp[q[r]][0]-sum[q[r]]&&l<=r)r--;
		q[++r]=i;
	}
	cout<<max(dp[n][0],dp[n][1]);
}
