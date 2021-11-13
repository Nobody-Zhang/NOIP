#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int f[3][6667];
char a[6667],b[6667];
int lena,lenb,now,pre;

int main()
{
	freopen ("lcs.in","r",stdin);
	freopen ("lcs.out","w",stdout);
	memset (f,0,sizeof (f));
	scanf ("%d%d",&lena,&lenb);
	scanf ("%s",a+1);
	scanf ("%s",b+1);
	for (register int i=1;i<=lena;i++)
	{
		now=i&1;
		pre=now^1;
		for (register int j=1;j<=lenb;j++)
		{
			f[now][j]=max (f[pre][j],f[now][j-1]);
			if (a[i]==b[j])
				f[now][j]=max (f[now][j],f[pre][j-1]+1);
		}
	}
	printf ("%d",f[lena&1][lenb]);
	return 0;
}
