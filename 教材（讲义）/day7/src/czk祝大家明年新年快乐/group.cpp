#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[2000005],dp[2000005],q[2000005][3],sum[20000005],maxx=0;
int main(){
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	dp[0]=0;dp[1]=a[1];q[1][1]=sum[1]-dp[1];q[1][2]=0;
	int qwq,QAQ,head=1,tail=1;
	for(int i=1;i<=n;i++){
		while(q[head][2]<i-k&&head<=tail)head++;
		QAQ=q[head][1];
		dp[i]=QAQ+sum[i];
		maxx=maxx>dp[i]?maxx:dp[i];
		qwq=dp[i-1]-sum[i];
		while(q[tail][1]<qwq&&tail>=head)tail--;
		tail++;
		q[tail][1]=qwq,q[tail][2]=i;
	}
	cout<<maxx<<endl;
	return 0;
}
