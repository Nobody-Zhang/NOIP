#include<bits/stdc++.h>
using namespace std;
int f[2][6668];
char a[6668],b[6668];
int main()
{
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	int n,m;
	
	scanf("%d%d",&n,&m);
	scanf("%s",a+1);
	scanf("%s",b+1);
	/*for(int i=1;i<=n;i++)
	{
		int now1=i&1,pre1=now1^1;
		for(int j=1;j<=m;j++)
		{	
			int now2=j&1,pre2=now2^1;
			if(a[i]==b[j])
			{
				f[now1][now2]=max(f[pre1][pre2]+1,f[now1][now2]);
			}
			else f[now1][now2]=max(f[pre1][now2],f[now1][pre2]);
		}
	}
	printf("%d\n",f[n&1][m&1]);*/
	
	for(int i=1;i<=n;i++)
	{
		int now1=i&1,pre1=now1^1;
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j])
			f[now1][j]=f[pre1][j-1]+1;
			else f[now1][j]=max(f[pre1][j],f[now1][j-1]);
		}
	}
	printf("%d\n",f[n&1][m]);
}
/*
5 6
abdac
adabac
*/
