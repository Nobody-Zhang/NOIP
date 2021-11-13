#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,ans[1005],bo[1005],gu[1005];
char book[1005][10],guest[1005][10];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++)
	ans[i]=-1;
	for(int i=1;i<=n;i++)
	scanf("%d",&bo[i]);
	sort(bo+1,bo+1+n);
	for(int i=1;i<=n;i++)
	{
		int x=0,z=bo[i];
		while(z!=0)
		{
			book[i][++x]=z%10;
			z/=10;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x;
		scanf("%d",&x);
		scanf("%d",&gu[i]);
		int y=0,z=gu[i];
		while(z!=0)
		{
			guest[i][++y]=z%10;
			z/=10;
		}
		for(int j=1;j<=n;j++)
		{
			int flag=1;
			if(bo[j]<gu[i])
			{
				flag=0;
				continue;
			}
			for(int k=1;k<=y;k++)
			{
				if(book[j][k]!=guest[i][k])
		    	{
		    		flag=0;
		    		break;
		     	}
			}
			if(flag)
			{
				ans[i]=bo[j];
				break;
			}
		}
	}
	for(int i=1;i<=q;i++)
	printf("%d\n",ans[i]);
	return 0;
}
