#include<bits/stdc++.h>
using namespace std;

int ans;
char x;

int main()
{
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	while(scanf("%c",&x)!=EOF)
		if(x!=' '&&x!='\n')
			ans++;
	printf("%d",ans);
	return 0;
}
