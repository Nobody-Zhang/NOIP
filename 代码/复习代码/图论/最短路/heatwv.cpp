#include<bits/stdc++.h>
using namespace std;
int mp[2501][2501],w[2501][2501],m,n,dis[2501],fir,las;
bool in[2501];
queue<int>q;
int main()
{
	scanf("%d%d%d%d",&m,&n,&fir,&las);
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		w[a][b]=w[b][a]=c;
		mp[a][++mp[a][0]]=b;
		mp[b][++mp[b][0]]=a;
	}
	q.push(fir);
	memset(dis,0x7f,sizeof(dis));
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
			int len=w[x][tmp];
			if(dis[x]>len+dis[tmp])
			{
				dis[x]=len+dis[tmp];
				if(in[x]==false)
				{
					q.push(x);
					in[x]=true;
				}
			}
		}
	}
	printf("%d",dis[las]);
	return 0;
}
