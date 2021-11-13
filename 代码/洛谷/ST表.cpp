#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int m,n,a[N],f[N][18];
int low[N];
int main()
{
	cin>>n>>m;
	//n是长度，m是询问 
	low[0]=-1;
	for(int i=1;i<=n;i++)
	 {
	 	scanf("%d",&a[i]);
	 	f[i][0]=a[i];
	 	low[i]=low[i/2]+1;
	 }
	for(int j=1;(1<<j)<=n;j++)
	 for(int i=1;i+(1<<(j-1))-1<=n;i++)
	  f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	int q,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&q,&w);
		printf("%d\n",max(f[q][low[w-q+1]],f[w-(1<<low[w-q+1])+1][low[w-q+1]]));
	}
	return 0;
}
