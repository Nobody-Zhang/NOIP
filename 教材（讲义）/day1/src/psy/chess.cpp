#include<bits/stdc++.h>
#define maxx 100005
using namespace std;
int ans=maxx,n,m;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int mapp[105][105],f[105][105];//f[i][j]:�������㵽(i,j)�����ٽ�� 
void dfs(int x,int y,int mon,bool judge)
{
	//��֦ 
	if(!mapp[x][y]) return ;
	if(mon>=f[x][y]) return ;//���������Ž� 
	
	if(x==m&&y==m)
	{
		ans=min(ans,mon);
		return ;
	}
	f[x][y]=mon;
	for(int i=0;i<=3;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<=0||xx>=m+1||yy<=0||yy>=m+1) continue;
		if(mapp[xx][yy])//��������������ɫ 
		{
			if(mapp[xx][yy]==mapp[x][y]) //��ɫ��ͬ 
			     dfs(xx,yy,mon,true);
			else dfs(xx,yy,mon+1,true);//��ɫ��ͬ 
		}
		else if(judge)//����ʹ��ħ����ֱ�ӽ���һ�����ӱ������������ӵ���ɫ�����Ա��ֵ�ǰ�����Ž⣩ 
		{
			mapp[xx][yy]=mapp[x][y];
			dfs(xx,yy,mon+2,false);
			mapp[xx][yy]=0;
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);//��1��2 
		mapp[x][y]=c+1;
	}
	memset(f,0x3f3f3f,sizeof(f));
	dfs(1,1,0,1);
	if(ans==maxx) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
