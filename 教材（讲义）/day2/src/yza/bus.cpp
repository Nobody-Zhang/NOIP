#include<bits/stdc++.h>
using namespace std;

int n,m,a[505][505],t[505];

int min(int x,int y)
{
	return x<y?x:y;
}

int search(int x,int tim)
{
	if(x==n+1)	return 0;
	if(tim<t[x])	return search(x,t[x]);
	if(a[x][tim-t[x]])	return a[x][tim-t[x]];
	
	int sum = 0, i = x;
	
	while(i <= n && t[i] <= tim)	
		sum+=t[i++];
		
	int res = tim*(i-x)-sum+search(i,tim+m);
	
	for(; i <= n ; i++)
	{
		sum+=t[i];
		res=min(res,t[i]*(i-x+1)-sum+search(i+1,t[i]+m));
	}
	
	return a[x][tim-t[x]] = res;
}

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&t[i]);
	sort(t+1,t+n+1);
	printf("%d",search(1,0));
	return 0;
}
