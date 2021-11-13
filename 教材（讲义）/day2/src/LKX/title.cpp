#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	char s[100000];
	gets(s);
	int t=strlen(s);
	
	int ans=t;
	
	for(int i=0;i<t;i++)
	{
		if(s[i]==' '||s[i]=='\n') 
		ans--;
	} 
	printf("%d\n",ans);
}

//Ca 45 
