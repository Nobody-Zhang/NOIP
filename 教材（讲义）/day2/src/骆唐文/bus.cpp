/*#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;

bool used[501];
int tt[501],t[501],repeat[4000001],zg[4000001],jump[4000001];
int n,m,num=0,ans=2147483647,flag,maxx,c=0;

inline bool cmp (const int &a,const int &b)
{
	return a<b;
}
int predict (int time,int val)
{
	int op=val;
	for (int i=num;i>=1;i--)
	{
		if (t[i]<=time)
			return op;
		if (t[i]-t[i-1]<m)
			op+=min (t[i-1]+m-t[i],t[i]-t[i-1]);
	}
}
void dfs (int time,int val,int al)
{
	if (val>=ans)
		return ;
	if (al==n)
	{
		ans=min (val,ans);
		return ;
	}
	if (time>maxx)
		return ;
	if (repeat[time-1]||repeat[time-m])
		if (predict(time,val)>ans)
			return ;
	int op=0;
	for (int i=time;i>=0;i--)
		if (zg[i])
		{
			op=zg[i];
			break ;
		}
	if (!jump[time])
		dfs (time+1,val+op-al,al);
	int sum=0,cnt=0;
	int b[501];
	for (int i=1;i<=num;i++)
	{
		if (used[i])
			continue ;
		if (t[i]>time)
			break ;
		used[i]=1;
		sum+=repeat[t[i]];
		b[++cnt]=i;
	}
	if (sum==0)
		return ;
	int opp=0;
	for (int i=1;i<=num;i++)
		if (t[i]>time&&t[i]<time+m)
			opp+=repeat[t[i]]*((time+m)-t[i]);
	if (jump[time])
		dfs (jump[time],val+op+opp-al-sum,al+sum);
	else
		dfs (time+m,val+op+opp-al-sum,al+sum);
	for (int i=1;i<=cnt;i++)
		used[b[i]]=0;
}

int main()
{
	freopen ("bus.in","r",stdin);
	freopen ("bus.out","w",stdout);
	memset (repeat,0,sizeof (used));
	memset (used,0,sizeof (used));
	scanf ("%d%d",&n,&m);
	for (register int i=1;i<=n;i++)
		scanf ("%d",&tt[i]);
	sort (tt+1,tt+n+1,cmp);
	flag=0;
	for (register int i=1;i<=n;i++)
	{
		t[++num]=tt[i];
		repeat[tt[i]]=1;
		if (tt[i]==tt[i+1])
			for (register int j=i+1;j<=n;j++)
				if (tt[j]==tt[i])
					repeat[tt[i]]++;
				else
				{
					i=j-1;
					break ;
				}
		zg[tt[i]]=zg[tt[flag]]+repeat[tt[i]];
		flag=i;
	}
	maxx=max (t[num-1]+m,t[num]);
	for (register int i=2;i<=num;i++)
		if (t[i]-t[i-1]>=m)
			jump[t[i-1]]=t[i];
	dfs (1,0,0);
	printf ("%d",ans);
	return 0;
}*/

#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;

long long ans;
long long f[501][210];
int t[501];
int n,m,op;

inline bool cmp (const int &a,const int &b)
{
	return a<b;
}
long long min (long long a,long long b)
{
	if (a<b)
		return a;
	return b;
}
long long ask(int line,int to)
{
	ans=0x7f7f7f7f;
	for(int i=0;i<=to;i++)
		ans=min (ans,f[line][i]);
	return ans;
}

int main()
{
	freopen ("bus.in","r",stdin);
	freopen ("bus.out","w",stdout);
	memset (f,0x7f7f7f7f,sizeof (f));
	scanf ("%d%d",&n,&m);
	for (register int i=1;i<=n;i++)
		scanf ("%d",&t[i]);
	sort (t+1,t+n+1,cmp);
	for (register int i=0;i<=2*m;i++)
		f[1][i]=i;
	for (register int i=2;i<=n;i++)
		for (int j=0;j<=2*m;j++)
		{
			op=t[i]-t[i-1]+j;
			if (op>=0&&op<=2*m)
				f[i][j]=min (f[i][j],f[i-1][op]+j);
			if (op>=m)
				f[i][j]=min (f[i][j],ask (i-1,min (op-m,2*m))+j);
		}
	ans=0x7f7f7f7f;
	for (register int i=0;i<=2*m;i++)
		ans=min (ans,f[n][i]);
	printf ("%lld",ans);
	return 0;
}
