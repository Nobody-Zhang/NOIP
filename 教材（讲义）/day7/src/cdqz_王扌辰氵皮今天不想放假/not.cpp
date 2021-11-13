#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,used[15];
long long ans,a[15];
int gcd(int x,int y)
{
	return (y==0)?x:gcd(y,x%y);
}
int lcm(int x,int y)
{
	return (x*y)/gcd(x,y);
}
void dfs(int x,int y,int p,long long tot)
{
	if(x==y+1)
	{
		if(y%2==1)
		ans+=m/tot;
		else if(y%2==0)
		ans-=m/tot;
	}
	for(int i=p;i<=n;i++)
	{
		if(used[i])continue;
		used[i]=1;
		dfs(x+1,y,i+1,lcm(tot,a[i]));
		used[i]=0;
	}
}
int main()
{
	freopen("not.in","r",stdin);
    freopen("not.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
    	dfs(1,i,1,1);
    	memset(used,0,sizeof(used));
    }
    printf("%I64d",m-ans);
    return 0;
}
