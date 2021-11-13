#include<stdio.h>
int md[16]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
int a[1024];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	while(q--)
	{
		int l,nn;
		scanf("%d%d",&l,&nn);
		if(l>8)
		{
			l=8;
		}
		int ans=-1;
		for(int i=0;i<n;i++)
		{
			if(a[i]%md[l]==nn)
			{
				if(ans<0||a[i]<ans)
				{
					ans=a[i];
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
