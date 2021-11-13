#include<bits/stdc++.h>
using namespace std;

int m,n;
int ans=0x3f3f3f;
bool bj=false;
int mp[105][105];
int val[105][105];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void dfs(int x,int y,bool bj,int s){
	if(s>=val[x][y]) return;//剪枝同时避免回过来走 
	val[x][y]=s;
	if(x==m&&y==m)  return;
	for(int i=0;i<=3;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>m||xx<=0||yy>m||yy<=0) continue;
		if(mp[x][y]==mp[xx][yy])  dfs(xx,yy,true,s);//相同颜色 
		else if(mp[xx][yy])    dfs(xx,yy,true,s+1);//有颜色但不同 
		else{//无色 
			if(bj) {//当前处于本来颜色块上 
				mp[xx][yy]=mp[x][y];//涂成当前块色,贪心 
				dfs(xx,yy,false,s+2);//标记变为不能用魔法 
				mp[xx][yy]=0;// 回溯 
			}
		}
	}
}


int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		z++;
		mp[x][y]=z;
	}
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=m;j++)
	    val[i][j]=0x3f3f3f;
	
	dfs(1,1,true,0);
	/*for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)
		 printf("%10d ",val[i][j]);
		printf("\n");
	}*/
	if(val[m][m]!=0x3f3f3f)
	printf("%d",val[m][m]);
	else printf("-1");
}
/*5 7              
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0
*/
