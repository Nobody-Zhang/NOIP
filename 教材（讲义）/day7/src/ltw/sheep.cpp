#include<cstdio>
#include<algorithm>
#include<memory.h>
#include<cmath>
using namespace std;

double f[100100],hzh[100001];
int jump[100001];
int T,n,m,x,y;

/*void work ()
{
	f[n]=0;
	hzh[n]=0;
	for (register int i=n-1;i>=0;i--)
	{
		if (!jump[i])
		{
			//f[i]=(((double)(n-i)/(n-i+1))*hzh[i+1])+((double)((n-i)*(n-i)+i+1)/(n-i+1));
			//f[i]=(((double)(n-i-1)/(n+1))*hzh[i+1])+((double)(n-i+1)/(n+1));
			//f[i]=(((double)(n-i-1)/(n+1))*hzh[i+1])+((double)(n-i+1)/(n+i+1));
			f[i]=(((double)(n-i-1)/(n+1))*hzh[i+1])+((double)(n-i+1)/(n+i+1));
			hzh[i]=hzh[i+1]+f[i];
		}
		else
		{
			f[i]=f[jump[i]];
			hzh[i]=hzh[i+1]+f[i];
		}
	}
	for (register int i=0;i<=n;i++)
		printf ("%0.2lf ",f[i]);
	printf ("\n");
}*/

void work ()
{
	for (register int i=n-1;i>=0;i--)
	{
		if (!jump[i])
		{
			for (register int j=1;j<=6;j++)
				f[i]+=(f[i+j]/6.0);
			f[i]++;
		}		
		else
			f[i]=f[jump[i]];
	}
	printf ("%0.2lf\n",f[0]);
}

int main()
{
	freopen ("sheep.in","r",stdin);
	freopen ("sheep.out","w",stdout);
	scanf ("%d",&T);
	for (register int i=1;i<=T;i++)
	{
		memset (f,0,sizeof (f));
		memset (jump,0,sizeof (jump));
		scanf ("%d%d",&n,&m);
		for (register int j=1;j<=m;j++)
		{
			scanf ("%d%d",&x,&y);
			jump[x]=y;
		}
		work ();
	}
}
