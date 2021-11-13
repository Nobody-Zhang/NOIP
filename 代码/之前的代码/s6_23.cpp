#include<bits/stdc++.h>
using namespace std;
int a[105][105],l[105][105],c[105][105];
int main()
{
	int M,N,k;//第一个m*n，第二个n*k 
	scanf("%d%d%d",&M,&N,&k);
	for(int b=1;b<=M;b++)
	 for(int v=1;v<=N;v++)
	  scanf("%d",&a[b][v]);
	for(int b=1;b<=N;b++)
	 for(int v=1;v<=k;v++)
	  scanf("%d",&l[b][v]);
	for(int i=1;i<=M;i++)	  
	 for(int j=1;j<=k;j++)
	  for(int p=1;p<=N;p++)
	   c[i][j]+=a[i][p]*l[p][j];
	for(int b=1;b<N;b++)
	 {
	 	for(int v=1;v<=k;v++)
	  	printf("%d ",c[b][v]);
	  	printf("\n");
	 }
}
