#include<bits/stdc++.h>

using namespace std;

char s[15];

int ans=0;

int main()
{
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	for(int i=1;i<=15;i++)
	{
		scanf("%c",&s[i]);
		if((s[i]<=122&&s[i]>=97)||(s[i]<=90&&s[i]>=65)||(s[i]<=57&&s[i]>=48))
		ans++;
	}
	printf("%d",ans);
	return 0;
}
