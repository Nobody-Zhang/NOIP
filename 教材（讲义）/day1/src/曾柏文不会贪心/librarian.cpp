#include<bits/stdc++.h>

using namespace std;

int n,q,len[2000],ma[2000];

int po[9]={1,10,100,1000,10000,100000,1000000,10000000,100000000}; 

inline void search(int k,int x)
{
	for(int i=1;i<=n;i++)
		if((ma[i]-x)%po[k]==0)
			{printf("%d\n",ma[i]);return;}
	printf("-1\n");
	return;
}

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&ma[i]);
	sort(ma+1,ma+1+n);
	for(int k=1;k<=q;k++)
	{
		int zz,id;
		scanf("%d%d",&zz,&id);
		search(zz,id);
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
