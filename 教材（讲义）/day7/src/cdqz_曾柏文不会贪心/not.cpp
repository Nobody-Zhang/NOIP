#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,a[11],aa[11],sum[11][3000],cnt=1,ans=0,num[11],tot=0;
int main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&aa[i]);
	sort(aa+1,aa+1+n);
	for(int i=n;i>=1;i--)//去重 
	{
		bool bz=true;
		for(int j=i-1;j>=1;j--)
			if(aa[i]%aa[j]==0){bz=false; break;}
		if(bz==true){a[++tot]=aa[i]; sum[1][tot]=(m-m%a[tot])/a[tot];}
	}
	num[1]=tot;
	n=tot;
	if(n==1)//特判 
	{
		printf("%I64d",m-sum[1][1]);
		return 0;
	}
	if(n==2)//特判
	{
		long long kkk=a[1]*a[2];
		if(m<kkk){printf("%I64d",m-sum[1][1]-sum[1][2]); return 0;}
		sum[2][1]=(m-m%kkk)/kkk;
		printf("%I64d",m-sum[1][1]-sum[1][2]+sum[2][1]);
		return 0;
	}
	else//容斥定理 
	{
		for(int t=2;t<=n;t++)
		{
			cnt++;tot=0;
			for(int i=1;i<=n;i++)
				for(int j=i;j<=n;j++)
				{
					if(i==j) continue;
					long long kkk=a[i]*a[j];
					if(kkk>m) continue;
					sum[cnt][++tot]=(m-m%kkk)/kkk;
				}
			num[t]=tot;
		}
		for(int i=1;i<=n;i++)
		{
			if(i%2==1)
				for(int j=1;j<=num[i];j++)
					ans+=sum[i][j];
			else
				for(int j=1;j<=num[i];j++)
					ans-=sum[i][j];
		}
		printf("%I64d",m-ans);
		return 0;
	}
}
