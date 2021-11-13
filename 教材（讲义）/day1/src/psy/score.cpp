#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int ans=a*20/100+b*30/100+c*50/100;
	printf("%d",ans);
	return 0;
}
