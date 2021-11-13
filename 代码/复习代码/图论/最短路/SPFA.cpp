#include<bits/stdc++.h>
using namespace std;
queue<int>q;
int m,n,add[101][3],con[101][101];
double dis[101],w[101][101];
bool in[101];//判断是不是在队列里面 
double len(int a,int b) {
	return sqrt(pow((add[a][1]-add[b][1]),2)
	+pow((add[a][2]-add[b][2]),2));
}
int main()
{
	freopen("short.in","r",stdin);
	freopen("short_SPFA.out","w",stdout);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	 scanf("%d%d",&add[i][1],&add[i][2]);
	scanf("%d",&n);
	memset(w,0x7f,sizeof(w));
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		w[a][b]=w[b][a]=len(a,b);
		con[a][++con[a][0]]=b;
		con[b][++con[b][0]]=a;//数组模拟邻接表
	}
	int fir,end;
	memset(in,false,sizeof(in));
	scanf("%d%d",&fir,&end);
	memset(dis,0x7f,sizeof(dis));
	dis[fir]=0;
	/*for(int i=1;i<=m;i++)
	 cout<<dis[i]<<endl;
	for(int i=1;i<=m;i++)
	 {
	 	for(int j=1;j<=con[i][0];j++)
	 	 cout<<con[i][j]<<" ";
	 	cout<<endl;
	 }*/
	q.push(fir);
	in[fir]=true;
	while(!q.empty()){
		int tmp=q.front();
		q.pop();
		in[tmp]=false;//表示已经没有在里面了 
		for(int i=1;i<=con[tmp][0];i++)
		 {
		 	int x=con[tmp][i];
		 	double length=w[tmp][x];
		 	if(dis[x]>dis[tmp]+length)
		 	{
		 		dis[x]=dis[tmp]+length;
		 		if(in[x]==false){
		 			q.push(x);
		 			in[x]=true;
		 		}
		 	}
		 }
	};
	printf("%.2lf",dis[end]);
	return 0;
}
