#include<bits/stdc++.h>
using namespace std;
int ditu[1500][1500];
int a[2500][2500];
int dp[2500][2500];
int used[1000010];
bool flag;
int n,m,x,y,v,mi,cost;
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,-1,1};
void dfs(int xxx,int yyy,int cost,bool flag)//flagΪħ����� 
{
	if(xxx<1||yyy<1||xxx>n||yyy>n)
	{
		return;
	}
	if(ditu[xxx][yyy]==0)
	{
		return;
	}
	if(cost>=dp[xxx][yyy])
	{
			return;
	}//��֦
	dp[xxx][yyy]=cost;//����ֵ 
	if(xxx==n&&yyy==n)
	{
		if(cost<mi)
		{
			mi=cost;
		}
		return;
	}
	for(int i=1;i<=4;i++)
	{
		int xx=xxx+dx[i];
		int yy=yyy+dy[i];
		if(ditu[xx][yy])//����ɫ 
		{
			if(ditu[xx][yy]==ditu[xxx][yyy])//��ɫһ�� 
			{
				dfs(xx,yy,cost,false); 
			}
			else
			{
				dfs(xx,yy,cost+1,false);
			}
		} 
		else
		{
			if(!flag)//δʹ��ħ��
			{
				ditu[xx][yy]=ditu[xxx][yyy];//��Ϊ��ǰ����ɫ
				dfs(xx,yy,cost+2,true);//���Ѽ�2
				ditu[xx][yy]=0;//ħ������ 
			} 
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	mi=987654321;
	memset(dp,0x7f,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ditu[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&v);
		ditu[x][y]=v+1;
	}
	dfs(1,1,0,false);
	if(mi==987654321)
	{
		printf("-1\n");
	}
	else
	{
		cout<<mi;
	}
	return 0;
}

/*
5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0
*/

