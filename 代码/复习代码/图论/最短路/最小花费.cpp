#include<bits/stdc++.h>
using namespace std;
int m,n,mp[2001][2001];
double len[2001][2001],dis[2001];
bool in[2001];
queue<int>q;
int main()
{
	freopen("最小花费.in","r",stdin);
	memset(in,false,sizeof(in));
	scanf("%d%d",&m,&n);
	memset(len,0x7f,sizeof(len));
	for(int i=1;i<=n;i++)
	 {
	 	int a,b,much;
	 	scanf("%d%d%d",&a,&b,&much);
	 	mp[a][++mp[a][0]]=b;
		mp[b][++mp[b][0]]=a;
		double tmp=much*1.00/100;
		len[a][b]=len[b][a]=1.0-tmp;
	 }
	int fir,las;
	scanf("%d%d",&fir,&las);
	q.push(fir);
	in[fir]=true;
	for(int i=1;i<=2000;i++)
	 dis[i]=0.00001;
	dis[fir]=1.00;
	while(!q.empty())
	{
		int tmp=q.front();
		q.pop();
		in[tmp]=false;
		//cout<<dis[tmp]<<endl;
		for(int i=1;i<=mp[tmp][0];i++)
		{
			int x=mp[tmp][i];
			//cout<<length<<endl;
			//cout<<dis[x]<<endl;
			//cout<<dis[tmp]*length<<endl;
			//printf("%.3lf\n",&dis[x]);
			if(dis[x]<dis[tmp]*len[x][tmp]){
				dis[x]=dis[tmp]*len[x][tmp];
				//cout<<dis[x]<<endl;
				if(in[x]==false){
					q.push(x);
					in[x]=true;
				}
			}
		}
	}
	double ans=100.00/dis[las];
	printf("%.8lf",ans);
}
