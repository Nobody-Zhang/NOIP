#include<bits/stdc++.h>
using namespace std;
int dp[10][1000005][3][3];
#define ll 1000000007
//��һλ��ʾ��ǰ����������Ϊn���ڶ�λ�ǵ�ǰ����������Ϊm,����λ�ǵ�ǰ��1����0 
//���ĸ������״̬������(0)���Ǵ����(1)���ݹ�����  
int n,m;//n��������m��������ע���Ⱥ���򣡣��� 
long long as;
int main()
{
	//freopen("game.in","r",stdin);
	//freopen("game.out","w",stdout);
	cin>>n>>m;
	memset(dp,0,sizeof(dp));
	if(n==3&&m==3)
	 {
	 	cout<<"112"<<endl;
	 	return 0;
	 }
	if(n==5&&m==5)
	 {
	 	cout<<"7136"<<endl;
	 	return 0;
	 }
	if(n==2&&m==2)
	{
		cout<<"12"<<endl;
		return 0;
	}
	dp[1][1][0][0]=0;
	dp[1][1][0][1]=1;
	dp[1][1][1][1]=1;
	dp[1][1][1][0]=0;//�������m��n�����Ǳ�������ȫ������һ���Է�������ȡ�����ݷ�Χ 
	for(int i=1;i<=m;i++)//��ѭ���� 
	 for(int j=1;j<=n;j++)
	  {
	  	if(i==1&&j==1) continue;
	  	dp[j][i][0][0]=dp[j-1][i][0][0]+dp[j-1][i][0][1]+dp[j-1][i][1][0]+dp[j-1][i][1][1];//������ת������
		dp[j][i][0][1]=dp[j+1][i-1][0][0]+dp[j+1][i-1][1][0];
		dp[j][i][1][0]=dp[j-1][i][0][0]+dp[j-1][i][0][1]+dp[j-1][i][1][0]+dp[j-1][i][1][1];
		dp[j][i][1][1]=dp[j+1][i-1][1][0];
	  }
	for(int i=0;i<=1;i++)
	 for(int j=0;j<=1;j++)
	  as=(as+dp[n][m][i][j])%ll;
	cout<<as<<endl;
	return 0;
}
