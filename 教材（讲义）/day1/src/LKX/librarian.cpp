#include<bits/stdc++.h>
using namespace std;
#define maxn 1002
int f1[maxn][8];
int f2[maxn][8];
int len1[maxn];
int w[maxn],a[maxn];
int vis[maxn];

int ask1(int a,int t)
{
	int cnt=10,tot=1;
	while(a%cnt!=a) 
	{
		f1[t][tot]=a%cnt;
		cnt*=10;
		tot++;	
	}
	if(a%cnt==a)
	f1[t][tot]=a;
	return tot;
}

int ask2(int a,int t)
{
	int cnt=10,tot=1;
	while(a%cnt!=a) 
	{
		f2[t][tot]=a%cnt;
		cnt*=10;
		tot++;	
	}
	if(a%cnt==a)
	f2[t][tot]=a;
	 return tot;
}

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	int len2[maxn];
	scanf("%d%d",&n,&q);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);	
		
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		len2[i]=ask1(a[i],i);
	}
	
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&len1[i]);
		scanf("%d",&w[i]);	
		len1[i]=ask2(w[i],i);
	}
	
	for(int i=1;i<=q;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(len1[i]>len2[j]) continue;
			if(f1[j][len1[i]]==f2[i][len1[i]]&&vis[i]!=1) 
			{
				vis[i]=1;
				printf("%d\n",a[j]);	
			}
		}	
		if(vis[i]!=1)
		printf("-1\n");
	}
	return 0;
}
/*
5 5
2123
1123
23
24
24
2 23
3 123
3 124
2 12
2 12
*/
