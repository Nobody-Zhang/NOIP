#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int n,len[100001],a[5001],pos[5001],shu[5001];
long long ans;
long long C(int x)
{//x是下标，y是上标
	return (x-1)*x/2;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&len[i]);
		a[len[i]]++;//储存当前有多少个
	}
	sort(len+1,len+n+1);
	for(int i=1;i<=5000;i++){
		if(a[i]>=2) {//桶排序
			pos[0]++;//存储有多少根木柴棒
			pos[pos[0]]=i;//储存有多少根木柴
		}
		if(a[i]){
			shu[0]++;
			shu[shu[0]]=i;
		}
	}
	for(int i=1;i<=pos[0];i++)
	{
		for(int j=1;j<=shu[0];j++)
		{
			double tmp=pos[i]*1.0/2;
			if(shu[j]>tmp) break;
			if(shu[j]==tmp)
			{
				if(a[shu[j]]<2) break;
				ans=ans+C(a[shu[j]])*C(a[pos[i]]);
				ans%=mod;
				break;
			}
			if(a[pos[i]-shu[j]]){
				ans=ans+a[shu[j]]*a[pos[i]-shu[j]]*C(a[pos[i]]);
				ans%=mod;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}