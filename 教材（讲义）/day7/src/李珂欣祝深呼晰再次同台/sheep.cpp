#include<bits/stdc++.h>
using namespace std;
//���������ƣ�������˳��
#define maxn 100005

double dp[maxn];
int jmp[maxn];

int main()//dp[i]��f[i]Ϊ��i��������,�뿪���������������������ô��ξͳ����� 
{ 
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		memset(jmp,0,sizeof(jmp));
		memset(dp,0,sizeof(dp));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int w=1;w<=m;w++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			jmp[a]=b;
		}
		for(int j=n-1;j>=0;j--)
		{
			dp[j]=0;
			if(!jmp[j])
			for(int k=1;k<=6;k++)
			dp[j]+=(dp[j+k]+1)/6;
			else dp[j]=dp[jmp[j]];
		}
		printf("%0.2lf\n",dp[0]);
	}
}
/*
2
2 0
8 3
2 4
4 5
7 8
*/
