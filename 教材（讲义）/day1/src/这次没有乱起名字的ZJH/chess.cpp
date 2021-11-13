#include<bits/stdc++.h>
using namespace std;
int m,n,mp[103][103],ct[103][103];
int h1=0,t1=1,f[50030][4];//0 x  1 y  2 cost 3 ?color
int fx[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int ans = 0x7f7f7f;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	int a,b,c;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a,&b,&c);
		mp[a][b]=c+1;//0 no 1 red 2 yellow 
	}
	for(int i=1;i<=102;i++){
		for(int j=1;j<=102;j++)
		ct[i][j]=0x7f7f7f;
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=m;j++)
//		cout<<mp[i][j]<<" ";
//		cout<<endl;
//	}
	f[1][0]=1;f[1][1]=1;ct[1][1]=0;
	do{
		h1++;
		for(int i=0;i<4;i++){
			int xx=f[h1][0]+fx[i][0],yy=f[h1][1]+fx[i][1];
			if(xx>0&&yy>0&&xx<=m&&yy<=m){
//				cout<<xx<<" "<<yy<<endl;  
				if(!mp[xx][yy]){
					if(!f[h1][3]&&f[h1][2]+2<ct[xx][yy]){
						f[++t1][0]=xx;f[t1][1]=yy;f[t1][2]=f[h1][2]+2;ct[xx][yy]=f[h1][2]+2;f[t1][3]=mp[f[h1][0]][f[h1][1]];
					}
				}
				else if(mp[f[h1][0]][f[h1][1]]==mp[xx][yy]||f[h1][3]==mp[xx][yy]){
					if(f[h1][2]<ct[xx][yy]){
						f[++t1][0]=xx;f[t1][1]=yy;f[t1][2]=f[h1][2];ct[xx][yy]=f[h1][2];
					}
					
				}
				else if(f[h1][2]+1<ct[xx][yy]){
					f[++t1][0]=xx;f[t1][1]=yy;f[t1][2]=f[h1][2]+1;ct[xx][yy]=f[h1][2]+1;
				}
			}
		}
	}while(h1<t1);
	if(ct[m][m]!=0x7f7f7f)
	printf("%d",ct[m][m]);
	else printf("-1");
//	
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=m;j++)
//		cout<<ct[i][j]<<" ";
//		cout<<endl;
//	}
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

8 19
1 1 0
1 2 1
2 2 0
3 2 1
3 1 0
4 1 0
5 1 0
5 2 1
6 2 0
7 2 1
7 1 0
8 1 0
8 2 0
8 3 0 
8 4 0
8 5 0
8 6 0
8 7 0
8 8 0
*/
