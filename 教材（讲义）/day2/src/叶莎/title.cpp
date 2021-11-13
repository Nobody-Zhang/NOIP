#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	char s[10];
	int ans=0;
	//scanf("%s",s);
	gets(s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]!=' '&&s[i]!='\n')
		ans++;
	}
	printf("%d",ans);
}
