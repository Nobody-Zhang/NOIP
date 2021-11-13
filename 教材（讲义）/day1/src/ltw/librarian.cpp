#include<stdio.h>
using namespace std;

int sws[16]={1,10,100,1000,10000,100000,1000000,10000000,100000000},op[1024];
int n,q,len,nn;

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(register int i=1;i<=n;i++)
		scanf("%d",&op[i]);
	for (register int j=1;j<=q;j++)
	{
		scanf("%d%d",&len,&nn);
		int ans=-1;
		for(int i=1;i<=n;i++)
			if(op[i]%sws[len]==nn)
				if(ans<0||op[i]<ans)
					ans=op[i];
		printf("%d\n",ans);
	}
	return 0;
}
