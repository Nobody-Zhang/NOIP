#include<bits/stdc++.h>
#define maxx 20000000
using namespace std;
bool b[10];
int qq[1005],l[1005];
int n,q,len,tot,m=-1;
struct node
{
	int father,fact;
}f[8005];
void markk(int u)
{
	int i=1;
	while(1)
	{
		int mod=pow(10,i);
		if(u%mod==u) 
		{
			f[++tot].father=u;
			f[tot].fact=u;
			break;
		}
		f[++tot].father=u;
		f[tot].fact=u%mod;
		i++;
	}
}
int lenth(int x)
{
	int cnt=0;
	while(x)
	{
		cnt++;
		x=x/10;
	}
	return cnt;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	memset(b,false,sizeof(b));
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		m=max(lenth(x),m);
		markk(x);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&l[i],&qq[i]);
	}	
	for(int i=1;i<=q;i++)
	{
		int ans=maxx;
		if(l[i]>m) 
		{
			printf("-1\n");
			continue;
		}
		for(int j=1;j<=tot;j++)
		{
			if(f[j].fact==qq[i])
            ans=min(ans,f[j].father);	
		}
    	if(ans!=maxx) printf("%d\n",ans);
		else  printf("-1\n");
	}
	return 0;
}
/*
5 5  212311232324242 233 1233 1242 122 12
*/
