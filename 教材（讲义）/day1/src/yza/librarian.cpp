#include<bits/stdc++.h>
using namespace std;

int n,q,a[1005],b[10],c[10];

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	b[0] = 1;
	for(int i=1;i<=9;i++)
		b[i] = b[i-1]*10;
	int p=1;
	c[0]=1;
	for(int i=1;i<=n;i++)
		while(b[p-1]<=a[i])
			c[p++] = i;
	for(int i=1;i<=q;i++)
	{
		int x,y,j;
		scanf("%d%d",&x,&y);
		for(j = c[x]; j <= n; j++)
			if((a[j]-y)%b[x]==0)
			{
				printf("%d\n",a[j]);
				break;
			}
		if(j>n)
			printf("-1\n");
	}
	return 0;
}
/*
5 5
2123
1023
23
24
24
2 23
3 123
3 124
2 12
2 12
*/
