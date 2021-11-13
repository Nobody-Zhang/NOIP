#include<bits/stdc++.h>
using namespace std;
const long long MaxN=2e6+5;
typedef pair<long long,int> pii;
template<class T> void read(T &re);

long long n,k,a[MaxN],dp[MaxN],pre[MaxN];
deque<pii> que;
//dp[i]=max(dp[j-1]-sum[j]) +sum[i]

long long tmp,tmax;
int main()
{
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	read(n);read(k);
	for(long long i=1;i<=n;i++){
		read(a[i]);
		pre[i]=pre[i-1]+a[i];
	}
	dp[1]=a[1];
	que.push_back(make_pair(0,0));
	for(int i=1;i<=n;i++){
		while(!que.empty()&&que.back().first<dp[i-1]-pre[i]) que.pop_back();
		tmp=dp[i-1]-pre[i];
		que.push_back(make_pair(dp[i-1]-pre[i],i));
		while(!que.empty()&&que.front().second<i-k) que.pop_front();
		tmax=que.front().first;
		if(i>1) dp[i]=que.front().first+pre[i];
	}
	printf("%I64d\n",dp[n]);
	return 0;
}

template<class T> void read(T &re)
{
	re=0;
	T sign=1;
	char tmp;
	while((tmp=getchar())&&(tmp<'0'||tmp>'9')) if(tmp=='-') sign=-1;
	re=tmp-'0';
	while((tmp=getchar())&&(tmp>='0'&&tmp<='9')) re=re*10+(tmp-'0');
	re*=sign;
}
