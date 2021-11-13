#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int a[15];
int b[100000000];
int n,m;
int cnt=0;

int com(int a,int b)
{
	return a<b;
}

int main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		
		scanf("%d",&a[i]);
		if(a[i]==1) cnt++;
	}
	if(cnt!=0) {printf("0\n"); return 0;}
	sort(a+1,a+n+1,com);
	int ans=m;
	int j=a[1];
	int t=1;
	while(t<=n)
	{
		for(int i=j;i<=m;i++)
			if(!b[i])
			{
				if(i%a[t]==0) {b[i]=1; ans--;}
				else continue;
			}
		t++;
	}
	printf("%d\n",ans);
	return 0;
}
