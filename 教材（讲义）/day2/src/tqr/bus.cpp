#include<bits/stdc++.h>
#define fo(i,j,k) for(register int i=j;i<=k;i++)
#define N 505
#define M 205
using namespace std;

int n,m;
int x,ans=1e9;
int t[N],f[N][M];

template<class T> inline void read(T &re)
{
	re=0;T sign=1;char tmp;
	while((tmp=getchar())&&(tmp<'0'||tmp>'9')) if(tmp=='-') sign=-1;re=tmp-'0';
	while((tmp=getchar())&&(tmp>='0'&&tmp<='9')) re=re*10+(tmp-'0');re*=sign;
}

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	read(n);read(m);x=m*2;
	fo(i,1,n) read(t[i]);
	sort(t+1,t+n+1);
	fo(i,1,n)
	{
		f[i][0]=1e9;
		fo(j,0,min(t[i]-t[i-1]-m,m-1))
			f[i][0]=min(f[i][0],f[i-1][j]);
		fo(j,1,x-1)
		{
			if (t[i]+j-t[i-1]-m>=0&&t[i]+j-t[i-1]-m<x)
				f[i][j]=min(f[i][j-1],f[i-1][t[i]+j-t[i-1]-m]);
			else f[i][j]=min(f[i][j-1],1000000000);
		}
		fo(j,0,x-1)
		{
			if (t[i]+j-t[i-1]<x)
				f[i][j]=min(f[i][j],f[i-1][t[i]+j-t[i-1]])+j;
			else f[i][j]=min(f[i][j],1000000000)+j;
		}
	}
	fo(i,0,m-1) ans=min(ans,f[n][i]);
	printf("%d\n",ans);
	return 0;
}
/*
5 1
3 4 4 3 5

5 5
11 13 1 5 5
 */
