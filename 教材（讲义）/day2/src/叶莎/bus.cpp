#include<bits/stdc++.h>
using namespace std;
int t[503],memory[503][504];
int ans=210000000,n,m;
int dfs(int i,int st)
{
	if(i==n+1) return 0;
	if(st<t[i]) return dfs(i,t[i]);
	if(memory[i][st-t[i]]) return memory[i][st-t[i]];
	int sum=0,j=i;
	while(j<=n&&t[j]<=st) sum+=t[j++];
	int best=st*(j-i)-sum+dfs(j,st+m);
	for(;j<=n;j++)
	{
		sum+=t[j];
		best=min(best,t[j]*(j-i+1)-sum+dfs(j+1,t[j]+m));
	}
	return memory[i][st-t[i]]=best;
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%d",&t[i]);
	
	if(m==1){printf("0\n"); return 0;}
	sort(t+1,t+1+n);
	//dfs(1,0);
	printf("%d",dfs(1,0)); 
}
/*
5 1
3 4 4 3 5

5 5
11 13 1 5 5
*/
