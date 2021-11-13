#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	double ans;
	ans=a*0.2+b*0.3+c*0.5;
	printf("%0.0lf\n",ans);
}

