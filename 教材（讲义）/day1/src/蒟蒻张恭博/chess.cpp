#include<bits/stdc++.h>
using namespace std;
int mp[101][101],s[101][101],m,n;
int one[5]={0,1,-1,0,0},ano[5]={0,0,0,1,-1};
void dfs(int x,int y,int sum,bool flag)
{
	if(x==m&&y==m){
		s[m][m]=min(s[m][m],sum);
		return;
	}
	if(x>m||y>m||x<0||y<0) return;
	if(sum>=s[x][y]) return;
	s[x][y]=sum;
	for(int i=1;i<=4;i++)
	{
		int xx=x+one[i],yy=y+ano[i];
		if(mp[xx][yy]){
			if(mp[xx][yy]==mp[x][y]) dfs(xx,yy,sum,false);
			else dfs(xx,yy,sum+1,false);
		}
		else if(!mp[xx][yy]&&flag==false){
			mp[xx][yy]=mp[x][y];
			dfs(xx,yy,sum+2,true);
			mp[xx][yy]=0;
		}
	}
	return;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			s[i][j]=0x7fffffff;
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		mp[a][b]=c+1;
	}
	dfs(1,1,0,false);
	if(s[m][m]==0x7fffffff){
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<s[m][m]<<endl;
	return 0;
}
