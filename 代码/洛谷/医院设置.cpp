#include<bits/stdc++.h>
using namespace std;
#define N 101
struct tree{
	int last,data;
}tr[N*4+5];
int m,tot,num[N],head[N],res[N];
void add(int a,int b)
{
	tot++;
	tr[tot].data=b;
	tr[tot].last=head[a];
	head[a]=tot;
	return;
}
int dfs(int now,int papa,int floor)
{
	int tmp=0;
	for(int i=head[now];i;i=tr[i].last)
	{
		int son=tr[i].data;
		if(son==papa) continue;
		tmp+=dfs(son,now,floor+1);
	}
	
	 tmp+=num[now]*floor;
	 return tmp;
}
int main()
{
	//freopen("hos.in","r",stdin);
	int maxx=0x7fffffff;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	 {
	 	int a,b,c;
	 	scanf("%d%d%d",&a,&b,&c);
	 	num[i]=a;
	 	if(b!=0)
		{
	 		add(b,i);
	 		add(i,b);
	 	}
	 	if(c!=0)
	 	{
	 		add(i,c);
	 		add(c,i);
	 	}
	 }
	for(int i=1;i<=m;i++)
	 {
	 	res[i]=dfs(i,i,0);
	 	if(res[i]<maxx) maxx=res[i];
	 }
	printf("%d\n",maxx);
	return 0;
}
