#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[12],ans=0,n,m;
ll read()
{
	ll x=0,f=1; char s=getchar();
	while(s<'0'||s>'9'){ if(s=='-') f=-1; s=getchar();}
	while(s>='0'&&s<='9'){ x=x*10+s-'0'; s=getchar();}
	return x*f;
}
void solve()
{
	ll now=1;
	if(n>=2)
	{
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
		  	now=a[i]*a[j];
		  	if(now<=m) ans-=m/now;
		  	if(a[j]%a[i]==0) ans-=(m/a[j]);
		}
	}
	if(n>=3)
	{
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		{
			now=a[i]*a[j]*a[k];
			if(now<=m) ans+=m/now;
		}
	}
	if(n>=4)
	{
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int b=k+1;b<=n;b++)
		{
			now=a[i]*a[j]*a[k]*a[b];
			if(now<=m) ans-=m/now;
		}
	}
	if(n>=5)
	{
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int b=k+1;b<=n;b++)
		for(int c=b+1;c<=n;c++)
		{
			now=a[i]*a[j]*a[k]*a[b]*a[c];
			if(now<=m) ans+=m/now;
		}
	}
	if(n>=6)
	{
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int b=k+1;b<=n;b++)
		for(int c=b+1;c<=n;c++)
		for(int d=c+1;d<=n;d++)
		{
			now=a[i]*a[j]*a[k]*a[b]*a[c]*a[d];
			if(now<=m) ans-=m/now;
		}
	}
	if(n>=7)
	{
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int b=k+1;b<=n;b++)
		for(int c=b+1;c<=n;c++)
		for(int d=c+1;d<=n;d++)
		for(int e=d+1;e<=n;e++)
		{
			now=a[i]*a[j]*a[k]*a[b]*a[c]*a[d]*a[e];
			if(now<=m) ans+=m/now;
		}
	}
	if(n>=8)
	{
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int b=k+1;b<=n;b++)
		for(int c=b+1;c<=n;c++)
		for(int d=c+1;d<=n;d++)
		for(int e=d+1;e<=n;e++)
		for(int f=e+1;f<=n;f++)
		{
			now=a[i]*a[j]*a[k]*a[b]*a[c]*a[d]*a[e]*a[f];
			if(now<=m) ans-=m/now;
		}
	}
	if(n>=9)
	{
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int b=k+1;b<=n;b++)
		for(int c=b+1;c<=n;c++)
		for(int d=c+1;d<=n;d++)
		for(int e=d+1;e<=n;e++)
		for(int f=e+1;f<=n;f++)
		for(int g=f+1;g<=n;g++)
		{
			now=a[i]*a[j]*a[k]*a[b]*a[c]*a[d]*a[e]*a[f]*a[g];
			if(now<=m) ans+=m/now;
		}
	}
	if(n>=10)
	{
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int b=k+1;b<=n;b++)
		for(int c=b+1;c<=n;c++)
		for(int d=c+1;d<=n;d++)
		for(int e=d+1;e<=n;e++)
		for(int f=e+1;f<=n;f++)
		for(int g=f+1;g<=n;g++)
		for(int h=g+1;h<=n;h++)
		{
			now=a[i]*a[j]*a[k]*a[b]*a[c]*a[d]*a[e]*a[f]*a[g]*a[h];
			if(now<=m) ans-=m/now;
		}
	}
	printf("%I64d",m-ans);
}
int main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]<=m) ans+=m/a[i];
	}
	solve();
	return 0;
}
/*
2 100 
10 99

4 100
5 6 48 40
*/
