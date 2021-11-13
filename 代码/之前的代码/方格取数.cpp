#include<bits/stdc++.h>
using namespace std;
int m,mp[51][51],f[51][51][51][51];
int main()
{
	cin>>m;
	while(1)
	 {
	 	int j,n,l;
	 	cin>>j>>n>>l;
	 	if(j==0&&n==0&&l==0) break;
	 	mp[j][n]=l;
	 }
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=m;j++)
	  for(int k=1;k<=m;k++)
	   for(int n=1;n<=m;n++)
	    {
	    	int tmp1=max(f[i-1][j][k-1][n],f[i][j-1][k][n-1]);
	    	int tmp2=max(f[i-1][j][k][n-1],f[i][j-1][k-1][n]);
	    	f[i][j][k][n]=max(tmp1,tmp2)+mp[i][j];
	    	if(i!=k&&j!=n)f[i][j][k][n]+=mp[k][n];
	    }
	cout<<f[m][m][m][m];
	return 0;
}
