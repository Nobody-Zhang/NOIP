#include<bits/stdc++.h>
using namespace std;
char x;
int tot=0;
int main()
{
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	while(1)
	{
		x=getchar();
		if(x==EOF) break;
		if((x!=' ')&&(x!='\n')) tot++;
	}
	printf("%d",tot);
	return 0;
}
