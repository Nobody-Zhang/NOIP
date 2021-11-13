#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
long long ans;
int t,a[5],b[5],tot;
bool judge(long long now)
{
	for(int i=1;i<=tot;i++)
		if(now%b[i]!=a[i]) return false;
	return true;
}
int main()
{
	freopen("crt.in","r",stdin);
	freopen("crt.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		ans=0;
		scanf("%d",&tot);
		long long tmp=1;
		bool flag=true;
		for(int j=1;j<=tot;j++)
		{
			scanf("%d%d",&a[j],&b[j]);
			tmp*=b[j];
		}
		while(ans<=tmp){
			if(judge(ans))
			{
				printf("%I64d\n",ans);
				flag=false;
				break;
			}
			ans++;
		}
		if(flag)
		{
			printf("No\n");
		}
	}
}
