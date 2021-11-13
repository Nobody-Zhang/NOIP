#include<bits/stdc++.h>
using namespace std;
int mp[1001][1001],m,n,tot;
char c[10001];
int lr[]={0,0,1,0,-1};
int ud[]={0,1,0,-1,0};
int quee[1000001][3];
void bfs(int l,int r)
{
	for(int i=1;i<=4;i++)
	 {
	 	int xx=l+lr[i];
	 	int yy=r+ud[i];
	 	if(xx>=1&&yy>=1&&xx<=m&&yy<=n&&mp[xx][yy]==0)
	 	{
	 		mp[xx][yy]=2;
	 		bfs(xx,yy);
	 		tot++;
	 	}
	 }
}
int main()
{
	while(cin>>c);
	{
		m=strlen(c);
		n++;
		for(int i=1;i<=m;i++)
		 mp[n][i]=c[i-1]-'0';
	}
	int j=0,k=0;
	for(int i=1;i<=m;i++)
	 for(int t=1;t<=n;t++)
	 if(mp[i][t]==1)
	  {
	  	if(mp[i+1][t]==0) j=i+1,k=t;
	  	if(mp[i+1][t+1]==0) j=i+1,k=t+1;
	  	if(mp[i][t+1]==0) j=i,k=t+1;
	  	if(j!=0&&k!=0){
	  		bfs(j,k);
	  		cout<<tot<<endl;
	  		return 0;
	  	}
	  }
}
