#include<bits/stdc++.h>
using namespace std;
#define N 1005
#define oo 10000005
int n,Q;
char a[N][10],s[10];
int lenn[N],num[N],len;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a[i]);
		lenn[i]=strlen(a[i]);
		for(int j=0;j<=lenn[i]-1;j++)
		 num[i]=num[i]*10+a[i][j]-'0';
	}
	for(int ii=1;ii<=Q;ii++)
	{
		int ans=oo;
		scanf("%d%s",&len,s);
		for(int i=1;i<=n;i++)
		if(lenn[i]>=len)
		{
			bool flag=true;
			for(int j=1;j<=len;j++)
			 if(a[i][lenn[i]-j]!=s[len-j])
			  { flag=false; break; }
			if(flag)
			 ans=min(ans,num[i]);
		}
		if(ans!=oo)
		 printf("%d\n",ans);
		else 
		 printf("-1\n");
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
