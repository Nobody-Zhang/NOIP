#include<bits/stdc++.h>
using namespace std;

int a[5];

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a[1],&a[2],&a[3]);
	printf("%d\n",a[1]/5+a[2]*3/10+a[3]/2);
	return 0;
}