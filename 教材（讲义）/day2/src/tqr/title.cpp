#include<bits/stdc++.h>
using namespace std;

char c;
int cnt;

int main()
{
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	while(true)
	{
		c=getchar();
		if(c=='\n') break;
		if ('0'<=c&&c<='9') cnt++;
		if ('a'<=c&&c<='z') cnt++;
		if ('A'<=c&&c<='Z') cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}