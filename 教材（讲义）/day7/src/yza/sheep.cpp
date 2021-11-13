#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;

int T,fa[maxn],n,m;
double f[maxn];//f[i]为在i处掷骰子,离开区间的期望步数 

int father(int x)
{
	return x==fa[x]?x:fa[x]=father(fa[x]);
}

int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++)
			fa[i]=i;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int p=father(y);
			fa[x]=y;
		}
		double res=0.0;
		for(int i=n-1;i>=0;i--)
		{
			int p=father(i);
			if(p!=i)
			{
				f[i]=f[p];
				res=res+f[i]/6.0-f[i+6]/6.0;
				continue;
			}
			f[i]+=res;
			f[i]+=1.0;
			res=res+f[i]/6.0-f[i+6]/6.0;
		}
		printf("%0.2lf\n",f[0]);
		for(int i=0;i<=n;i++)
			f[i]=0;
	}
	return 0;
}
/*
2
2 0
8 3
2 4
4 5
7 8
*/
