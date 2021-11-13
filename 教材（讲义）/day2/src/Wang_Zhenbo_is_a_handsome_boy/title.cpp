#include<cstdio>
using namespace std;
char s[50];
int main()
{
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	int now=1,tot=0;
	scanf("%c",&s[now]);
	while(s[now]!='\n')
	{
		if(s[now]!=' ')
		tot++;
		scanf("%c",&s[++now]);
	}
	printf("%d",tot);
	return 0;
}
