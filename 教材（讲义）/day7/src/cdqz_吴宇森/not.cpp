#include<bits/stdc++.h>
using namespace std;

int n,m,a[25],t=-1,tot=0,b[25],ans=0;

long long gcd(long long a,long long b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

int lcm()
{
	if(tot==1)
	return a[b[tot]];
	else
	{
		long long tt=gcd(a[b[1]],a[b[2]]);
		long long x=(a[b[1]]*a[b[2]])/tt;
		for(int i=3;i<=tot;i++)
		{
			long long ttt=gcd(x,a[b[i]]);
			x=(x*a[b[i]])/ttt;
		}
		return x;
	}
}

void dfs(int now,int nowstep,int to,int cnt)
{
	if(nowstep==to)
	{
		long long x=lcm();
		ans+=t*(m/x);
		return;
	}
	for(int i=now+1;i<=n;i++)
	{
		b[cnt]=i;
		dfs(i,nowstep+1,to,cnt+1);
	}
}

int main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		t*=-1;
		tot++;
		dfs(0,0,tot,1);
	}
	printf("%d",m-ans);
	return 0;
}
/*
4 100
5 6 48 40
*/
