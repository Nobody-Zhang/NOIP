#include<bits/stdc++.h>
using namespace std;
int w[1003],power[11];
void init()
{
	power[0]=1;
	for(int i=1;i<=10;i++)
	  power[i]=power[i-1]*10;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	init();
	int  n,q,maxx=-1;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	  scanf("%d",&w[i]);
	for(int i=1;i<=q;i++)
	{
		int len,x;
		scanf("%d%d",&len,&x);
		int flagg=0,minn=21000000;
		for(int j=1;j<=n;j++)
		{
			if(w[j]%power[len]==x)
			{
				flagg=1;
				if(w[j]<minn) minn=w[j];
		    }
		}
		if(!flagg) printf("-1\n");
		else printf("%d\n",minn);
	}
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
