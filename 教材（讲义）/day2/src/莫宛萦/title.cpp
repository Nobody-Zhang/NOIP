#include<bits/stdc++.h>
using namespace std;
char a[10];
int ans=0;
int main()
{
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	while(scanf("%s",a)!=EOF)
	{
		ans+=strlen(a);
	}
	printf("%d\n",ans);
}
