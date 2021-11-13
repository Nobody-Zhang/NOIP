#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,tot_p,mn=0x3f3f3f3f,t[505],tot[505];
void dfs(int sum,int lf,int tm,int now,int ans)
{
	if(ans>mn)return;
	if(sum==tot_p)
	{
		if(ans<mn)mn=ans;
		return;
	}
	if(t[lf+1]-t[lf]>=m)
	dfs(sum+now,lf+1,t[lf+1],tot[lf+1],ans);//直接把现在的所有人送过去
	else
	{
		int i,delta_time=0,delta_people=0;
		for(i=lf+1;i<=n;i++)
		{
			if(t[i]>tm+m)break;
		    delta_time+=tot[i]*(tm+m-t[i]);
			delta_people+=tot[i];
		}
		dfs(sum+now,i-1,tm+m,delta_people,ans+delta_time);//把现在等车的人都送过去
		dfs(sum,lf+1,t[lf+1],now+tot[lf+1],ans+now*(t[lf+1]-t[lf]));//到下一个人再看
	}
}//送的人数，右端点，时间，等车的人数，共等的时间
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d",&n,&m);
	tot_p=n;
	for(int i=1;i<=n;i++)
	scanf("%d",&t[i]);
	sort(t+1,t+1+n);
	for(int i=1;i<=n;i++)
	{
		tot[i]=1;
		while(t[i]==t[i+1])
		{
			tot[i]++;
			for(int j=i;j<n;j++)
			t[j]=t[j+1];
			t[n]=0;
			n--;
		}
	}
	t[n+1]=0x3f3f3f3f;
	if(m==1)
	{
		printf("0");
		return 0;
	}
	dfs(0,1,t[1],tot[1],0);
	printf("%d",mn);
	return 0;
}
