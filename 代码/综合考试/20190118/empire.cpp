#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int m,n,k,tot;
int lr[]={0,0,1,-1,0};
int ud[]={0,1,0,0,-1};
bool mp[3001][3001],line[3010],rank[3010];
void dfs(int now)
{
	if(now==n)
	{
		tot++;
		tot%=504;
		return;
	}
	for(int i=1;i<=k;i++)
	 if(line[i]==false) 
	 {
	 	for(int j=1;j<=k;j++)
	 	 if(mp[i][j]==false&&line[i]==false&&rank[j]==false)//表示还可以走 
	 	 {
	 	 	line[i]=true;
	 	 	mp[i][j]=true;
	 	 	rank[j]=true;
	 	 	if(now+1==n) {
	 	 		tot++;
	 	 		tot%=504;
	 	 	}
	 	 	else dfs(now+1);
	 	 	mp[i][j]=false;
			line[i]=false;
			rank[j]=false;
	 	 }
	 }
}
void bj(int a,int b)
{
	for(int i=1;i<=4;i++)
	 {
	 	int x=a+lr[i];
	 	int y=b+ud[i];
	 	if(mp[x][y]==true&&x<=k&&y<=k&&(abs(x-m)+abs(y-m)<m)&&x>=1&&y>=1)
	 	{
	 		mp[x][y]=false;
	 		bj(x,y);
	 	}
	 }
	 return;
}
int main()
{
	freopen("empire.in","r",stdin);
	freopen("empire.out","w",stdout);
	memset(mp,true,sizeof(mp));
	scanf("%d%d",&m,&n);
	//cin>>m>>n;
	k=m*2-1;
	mp[m][m]=false;
	bj(m,m);
	dfs(0);
	printf("%d",tot/n);
	//cout<<tot/n<<endl;
	return 0;
}
