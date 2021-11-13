#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	char s[5005];
	gets(s);
	int cnt=0,len=strlen(s);
	for(int i=0;i<len;i++)
		if(s[i]!=' ') cnt++;
	printf("%d\n",cnt);
	return 0;
}