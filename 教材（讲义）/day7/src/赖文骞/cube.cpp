#pragma GCC optimize (2)
#include <cstdio>
#include <iostream>
using namespace std;
#define input(x) freopen(x,"r",stdin)
#define output(x) freopen(x,"w",stdout)

int n;
double a[100005];
bool path[100005];

double dfs(int now,double poss,bool get)
{
	path[now]=get;
	if(now==n)
	{
		int len=0;
		long long ret=0LL;
		
		for(int i=1;i<=n;i++)
		{
			if(path[i]) len++;
			else
			{
				ret+=(len*len*len);
				len=0;
			}
		}
		ret+=(len*len*len);
		
		return poss*(double)(ret);
	}
	
	return dfs(now+1,poss*a[now+1],true)+dfs(now+1,poss*(1.0-a[now+1]),false);
}

int main()
{
	input("cube.in");
	output("cube.out");
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
	
	printf("%.1lf",dfs(1,a[1],true)+dfs(1,1.0-a[1],false));
	return 0;
}
