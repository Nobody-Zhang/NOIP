#include<bits/stdc++.h>
using namespace std;
long long a[41][41],m,n;//a[i][j]表示第i到第j的数 
long long in,f[41][41];
int main()
{
	cin>>m>>n;//m是多少位的数字，n是多少个乘号 
	cin>>in;
	for(int i=1;i<=m;i++)
	{
		a[i][i]=in%10;
		in/=10;
	}
	for(int i=2;i<=m;i++)
	 for(int j=i-1;j>=1;j--)
	  a[j][i]=a[j][i-1]*10+a[i][i];	
	for(int i=1;i<=m;i++)
	 {
	 	for(int j=1;j<=m;j++)
		 cout<<a[i][j]<<" ";
		cout<<endl;
	 }
	for(int i=1;i<=n;i++)
	 f[i][0]=a[1][i];
	for(int k=1;k<=n;k++)//i是乘号个数 
	 for(int i=k+1;i<=m;i++)//j是第几位 
	  for(int j=k;j<i;j++)
	   f[i][k]=max(f[i][k],f[j][k-1]*a[j+1][i]);
	cout<<f[m][n]<<endl;
	for(int i=0;i<=m;i++)
	 {
	 	for(int j=1;j<=m;j++)
	 	 cout<<f[i][j]<<" ";
	 	cout<<endl;
	 }
	return 0;
}
