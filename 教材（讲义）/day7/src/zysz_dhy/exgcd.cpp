#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int t,a,b,c;

int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=10000;i++)
		{
			if(a*i%b==c) {printf("%d\n",i); break;}
			if(i==10000) {printf("no\n"); break;}
		}
	}
	return 0;
}
