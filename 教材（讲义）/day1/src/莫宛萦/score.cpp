#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int ans=a/5+(b/10)*3+c/2;
	printf("%d\n",ans);
}
/*
60 90 80
*/
