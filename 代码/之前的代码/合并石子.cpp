#include<bits/stdc++.h>
using namespace std;
int n,in[101],s[101],f[101][101];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>in[i],s[i]=s[i-1]+in[i];
	memset(f,127/3,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=n-1;i>=1;i--)
	 for(int j=i;j<=n;j++)
	  for(int k=i;k<=j-1;k++)
	   f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
	    //f[i][j][2]=max(f[i][j][2],f[i][k][2]+f[k+1][j][2]+s[j]-s[i]);
	cout<<f[1][n];
	return 0;
}/*
7
13 7 8 16 21 4 18
*/
