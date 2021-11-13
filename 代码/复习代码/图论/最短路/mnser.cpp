#include<bits/stdc++.h>
using namespace std;
int mp[101][101],w[101][101],m,n,dis[101];
queue<int>q;
bool in[101];
int main()
{
	//freopen("mnser.in","r",stdin);
	//freopen("mnser.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		w[a][b]=c;
		w[b][a]=c;
		mp[a][++mp[a][0]]=b;
		mp[b][++mp[b][0]]=a;
	}
	memset(dis,0x7f,sizeof(dis));
	for(int i=1;i<=m;i++)
	 if(mp[i][0]==0){
	 	printf("-1");
	 	return 0;
	 }
	int fir=1;
	q.push(fir);
	in[fir]=true;
	dis[fir]=0;
	while(!q.empty())
	{
		int tmp=q.front();
		q.pop();
		in[tmp]=false;
		for(int i=1;i<=mp[tmp][0];i++)
		{
			int x=mp[tmp][i];
			int length=w[tmp][x];
			if(dis[x]>dis[tmp]+length){
				dis[x]=dis[tmp]+length;
				if(in[x]==false)
				{
					q.push(x);
					in[x]=true;
				}   //这个地方要删去？？？ 
			}
		}
	}
	int maxx=0;
	//for(int i=1;i<=m;i++)
	 //cout<<dis[i]<<endl; 
	for(int i=1;i<=m;i++)
	 maxx=max(maxx,dis[i]);
	printf("%d",maxx);
	return 0;
}
