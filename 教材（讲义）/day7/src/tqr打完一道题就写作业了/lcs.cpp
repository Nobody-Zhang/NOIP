#include<bits/stdc++.h>
using namespace std;
const int MaxN=7000;

char s1[MaxN],s2[MaxN];
int n,m,dp1[MaxN],dp2[MaxN],*now=dp1,*pre=dp2,*tmp;

int main()
{
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s%s",s1+1,s2+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			now[j]= (s1[i]==s2[j]) ? pre[j-1]+1 : max(now[j-1],pre[j]);
		}
		tmp=now;now=pre;pre=tmp;
	}
	printf("%d\n",pre[m]);
	return 0;
}
