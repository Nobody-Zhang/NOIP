#include<bits/stdc++.h>
#define MAXX 101
using namespace std;
char mp[51][51][51];//地图存储，.可以走，S起点，E终点
bool used[MAXX][MAXX][MAXX];
int l,c,r,star[4],en[4],train[MAXX*1000][4],las[MAXX*1000];//l层，c长，r宽,star/en储存开始的地址和终止的地址
int step[7][4]={{0,0,0,0},{0,0,0,1},{0,0,0,-1},{0,0,1,0},{0,0,-1,0},{0,1,0,0},{0,-1,0,0}};//储存走法
void print(int now)
{
	int tot=1;
	while(las[now]){
		tot++;
		now=las[now];
	}
	printf("Escaped in %d minute(s).\n",tot);
	return;
}
void bfs()
{
	int head=0,tail=1;
	train[1][1]=star[1];
	train[1][2]=star[2];
	train[1][3]=star[3];//初始化最开始搜索的地方
	used[star[1]][star[2]][star[3]]=true;//把当前节点设置为true
	do{
		head++;
		for(int i=1;i<=6;i++)
		{
			if(used[train[head][1]+step[i][1]][train[head][2]+step[i][2]][train[head][3]+step[i][3]]==false&&mp[train[head][1]+step[i][1]][train[head][2]+step[i][2]][train[head][3]+step[i][3]]=='.'){
				//能满足条件
				used[train[head][1]+step[i][1]][train[head][2]+step[i][2]][train[head][3]+step[i][3]]=true;
				tail++;
				train[tail][1]=train[head][1]+step[i][1];
				train[tail][2]=train[head][2]+step[i][2];
				train[tail][3]=train[head][3]+step[i][3];
				las[tail]=head;
			}
			if(mp[train[head][1]+step[i][1]][train[head][2]+step[i][2]][train[head][3]+step[i][3]]=='E'){
				print(head);//进行回溯和输出
				return;
			}
		}
	}while(head<tail);
	printf("Trapped!\n");
	return;
}
int main()
{
	while(1)
	{
		memset(mp,0,sizeof(mp));
		memset(used,false,sizeof(used));
		memset(las,0,sizeof(las));
		scanf("%d%d%d",&l,&c,&r);
		if(l==0&&c==0&&r==0) return 0;
		for(int i=1;i<=l;i++)
			for(int j=1;j<=c;j++)
				for(int k=1;k<=r;k++)
					{
						cin>>mp[i][j][k];//直接输入
						if(mp[i][j][k]=='S') {
							star[1]=i;star[2]=j,star[3]=k;
						}
						if(mp[i][j][k]=='E'){
							en[1]=i;en[2]=j;en[3]=k;
						}
					}
		bfs();		
	}
}