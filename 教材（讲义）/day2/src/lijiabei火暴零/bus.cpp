#include<bits/stdc++.h>
using namespace std;
const int inf=1<<30;
int dp[750][750];//i���˵ȴ���iʱ����Сʱ�� f[i][j]��ʾ��ǰi������������һ�˳��ĳ���ʱ��Ϊa[i]+j ����С����
int Time[1000010];
int n,m;
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&Time[i]);
	}
	sort(Time+1,Time+1+n);
	for(int i=1;i<2*m;i++)//����ȴ���ʱ�䲻����2m 
	{
		dp[1][i]=i;//��ʼ��:һ���˵ȴ���ʱ��Ϊi 
	}
	for(int i=2;i<=n;i++)//�ӵڶ����˿�ʼö��
	{
		for(int j=0;j<2*m;j++)//ö�ٵȴ���ʱ��
		{
			dp[i][j]=inf;//��ʼ��Ϊ���ֵ
			for(int k=0;k<2*m;k++)//֮ǰ�˵ȴ���ʱ�� 
			{
				int check=Time[i]+j-(Time[i-1]+k);
				if(check==0||check>=m)
				{
					dp[i][j]=min(dp[i][j],dp[i-1][k]+j); 
				} 
			} 
		} 
	} 
	int ans=inf;
	for(int i=0;i<2*m;i++)
	{
		if(ans>dp[n][i])
		{
			ans=dp[n][i];
		}
	}
	cout<<ans<<endl;
	return 0;
}

