#include<bits/stdc++.h>
using namespace std;
int memory[505][105],t[505];
int n,m;
int solve(int i,int times)
{
	if(i==n+1) return 0;
	if(times<t[i]) return solve(i,t[i]);
	if(memory[i][times-t[i]]) return memory[i][times-t[i]];
	int sum=0,j=i;
	while(j<=n&&t[j]<=times)
	sum+=t[j++];
	int best=times*(j-i)-sum+solve(j,times+m);
	for( ;j<=n;j++)
	{
		sum+=t[j];
		best=min(best,t[j]*(j-i+1)-sum+solve(j+1,t[j]+m));
	}
	return memory[i][times-t[i]]=best;
	
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&t[i]);
	sort(t+1,t+n+1);
	printf("%d",solve(1,0));
	return 0;
}
