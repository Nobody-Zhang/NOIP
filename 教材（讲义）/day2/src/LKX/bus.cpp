#include<bits/stdc++.h>
using namespace std;
#define maxn 4000009
int cnt[maxn],t[maxn],sum[maxn],f[maxn];

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	
	int time=0;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
		cnt[t[i]]++;
		sum[t[i]]+=t[i];
		time=fmax(time,t[i]);
	}
	
	for(int i=1;i<time+m;i++)
	{
		cnt[i]+=cnt[i-1];
		sum[i]+=sum[i-1];
	}
	
	for(int i=0;i<time+m;i++)
	{
		if(i>=m&&cnt[i]==cnt[i-m])
		{
			f[i]=f[i-m];
			continue;
		}
		
		f[i]=cnt[i]*i-sum[i];
		
		int tmp;
		
		tmp=fmax(0,i-2*m+1);
		
		for(int j=tmp;j<=i-m;j++)
		{
			f[i]=fmin(f[i],f[j]+(cnt[i]-cnt[j])*i-(sum[i]-sum[j]));
		}
	}
	
	int ans=0x3f3f3f;
	
	for(int i=time;i<time+m;i++)
	{
		ans=fmin(ans,f[i]);
	}
	
	printf("%d\n",ans);
	
}
/*
5 1 
3 4 4 3 5 
*/
