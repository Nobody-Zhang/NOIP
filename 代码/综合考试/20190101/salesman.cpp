#include<bits/stdc++.h>
using namespace std;
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
template <typename T> inline void redi(T& t)
{
	register int c=getchar();t=0;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) t=t*10+c-'0',c=getchar();
}
template <typename T,typename... Args>inline void redi(T& t,Args&... args)
{
	redi(t);
	redi(args...);
}
int m,mp[16][16],minn;
bool bj[16];
bool judge()
{
	int mid1=rand()%m+1;
	if(bj[mid1]==false) return false;
	return true;
}
void dfs(int size,int data,int len)
{
	if(size==m)
	{
		if(judge())
		{
			minn=min(minn,len+mp[data][1]);
			return;
		}
	}
	for(int i=2;i<=m;i++)
	 if(bj[i]==false&&len+mp[data][i]<minn)
	 {
	 	bj[i]=true;
	 	dfs(size+1,i,len+mp[data][i]);
	 	bj[i]=false;
	 }
	return;
}
int main()
{
	//srand(time(0));
	freopen("salesman.in","r",stdin);
	freopen("salesman.out","w",stdout);
	minn=0x7fffffff;
	redi(m);
	//scanf("%d",&m);
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=m;j++)
	  redi(mp[i][j]);
	  //scanf("%d",&mp[i][j]);
	bj[1]=true;
	dfs(1,1,0);
	printf("%d",minn);
	return 0;
}
