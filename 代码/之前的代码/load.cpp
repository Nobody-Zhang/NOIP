#include<bits/stdc++.h>
using namespace std;
int n,c,m[55],ans=0,t=0,f[55];
void dfs(int s,int now)
{
	if(now+f[s]<=ans)
	return;
	if(now==c)
	{
		printf("%d",c);
		exit(0);
	}
	if(now>ans)
	ans=now;	
	for(int i=s;i<=n;i++)
	{
		if(now+m[i]<=c)
		{
			now=now+m[i];
			dfs(i+1,now);
			now=now-m[i];
		}
			
	}
}
int main()
{
	//freopen("load.in","r",stdin);
	//freopen("load.out","w",stdout);
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
		t=t+m[i];
	}
	f[n]=m[n];
	for(int i=n-1;i>=1;i--)
	f[i]=f[i+1]+m[i];
	if(t<=c)
	{
		printf("%d",t);
		return 0;
	}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
