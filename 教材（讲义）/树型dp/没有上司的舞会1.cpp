/*
    ����dp
    ��vector��ͼ���ҵ�û��boss���Ǹ��㣬������㿪ʼdfs
    ��ÿ���㶼�����������һ��ѡ�������ȡ�õ����ֵ�Ͳ�ѡȡ�����ֵ��dp[i][1]��ʾѡ�������ʱ�����ֵ�� dp[i][0]��ʾ��ѡ�����ȡ�����ֵ������ʽΪ dp[x][0]+=max(dp[i][1],dp[i][0]);dp[x][1]+=dp[i][0];
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector <int> G[6010];
int n,x,y;
int dp[6010][2];
int r[6010];
int boss[6010];
void dfs(int x)
{
    for(int j=0;j<G[x].size();j++)
    {
        int i=G[x][j];
        dfs(i);
        dp[x][0]+=max(dp[i][1],dp[i][0]);
        dp[x][1]+=dp[i][0];
    }
    dp[x][1]+=r[x];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&r[i]);
    while(scanf("%d%d",&x,&y)==2,x||y)
    {
        G[y].push_back(x);
        boss[x]=y;
    }
    for(int i=1;i<=n;i++)
        if(boss[i]==0)
        {
            dfs(i);
            printf("%d",max(dp[i][1],dp[i][0]));
            break;
        }
    return 0;
}
