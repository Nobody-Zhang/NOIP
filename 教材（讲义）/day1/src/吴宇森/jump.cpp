#include<bits/stdc++.h>
using namespace std;

const int N=5000000;
int n,d,k,x[N],s[N],ans=0,q[N];
long long dp[N],sum=0;
bool flag=false;

bool judge(int ans)
{
	memset(dp,-0x3f3f3f,sizeof(dp));
	memset(q,0,sizeof(q));
	dp[0]=0;
	int head=1,tail=0,minn=max(1,d-ans),maxx=d+ans,j=0;
	for(int i=1;i<=n;i++)
	{
		while(x[i]-x[j]>=minn&&j<i)
		{
			if(dp[j]!=-0x3f3f3f)
			{
				while(head<=tail&&dp[q[tail]]<=dp[j]) tail--;
				q[++tail]=j;
			}
			j++;
		}
		while(head<=tail&&x[i]-x[q[head]]>maxx) head++;
		if(head<=tail) dp[i]=dp[q[head]]+s[i];
		if(dp[i]>=k) return true;
	}
	return false;
}

void solve(int l,int r)
{
	while(l<r)
	{
		
		int mid=(l+r)/2;
		if(judge(mid))
		r=mid;
		else
		l=mid+1;
	}
	if(l!=x[n])
	printf("%d",l);
	else
	printf("-1");
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&s[i]);
		if(s[i]>0) sum+=s[i];
	}
	if(sum<k) 
	{
		printf("-1");
		return 0;
	}
	solve(1,x[n]);
	return 0;
}
/*
7 4 10
2 6
5 -3
10 3
11 -3
13 1
17 6
20 2
*/
/*
7 4 20
2 6
5 -3
10 3
11 -3
13 1
17 6
20 2
*/
