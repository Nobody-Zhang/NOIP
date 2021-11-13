#include<bits/stdc++.h>
using namespace std;

int ans=0;
char s[15];

int main()
{
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	gets(s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='z'))
		ans++;
	}
	printf("%d",ans);
	return 0;
}
