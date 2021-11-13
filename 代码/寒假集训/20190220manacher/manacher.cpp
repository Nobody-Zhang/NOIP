#include<cstdio>
#include<iostream>
#include<algorithm>
#include <string.h>
using namespace std;
#define maxn 1000005
char c[maxn<<1],t[maxn];
int len,pal[maxn*2];
void init()
{
	c[0]='+';
	for(int i=1;i<len*2;i+=2)
	{
		c[i]='#';
		c[i+1]=t[i/2];
	}
	c[len*2+1]='#';
	c[len*2+2]='-';
	c[len*2+3]='\0';
	len=2*len+1;
}
void manacher()
{
	int mx=0,id;
	for(int i=1;i<=len;i++)
	{
		if(mx>=i) pal[i]=min(mx-i+1,pal[2*id-i]);
		else pal[i]=1;
		while(c[i+pal[i]]==c[i-pal[i]]) 
			++pal[i];
		if(pal[i]+i-1>mx){
			mx=pal[i]+i-1;id=i;
		}
	}
	for(int i=1;i<=len;i++)
		cout<<c[i]<<" "<<pal[i]<<endl;
}
int main()
{
	int inc=0;
	while(1)
	{
		inc++;
		scanf("%s",&t);
		if(t[0]=='E'&&t[1]=='N') return 0;
		len=strlen(t);
		init();
		manacher();
		int ans=0;
		for(int i=1;i<=len;i++)
			ans=max(pal[i]-1,ans);
		printf("Case %d: %d\n",inc,ans);
	}
}
