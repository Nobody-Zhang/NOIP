#include<bits/stdc++.h>
using namespace std;
int in[1005][1005],m,maxx[1005][1005],as;
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=i;j++)
	  cin>>in[i][j];
	maxx[1][1]=in[1][1];
	for(int i=2;i<=m;i++)
	 for(int j=1;j<=i;j++)
	  maxx[i][j]=max(maxx[i-1][j-1],maxx[i-1][j])+in[i][j];
	for(int i=1;i<=m;i++)
	 as=max(as,maxx[m][i]);
	cout<<as<<endl;
	return 0; 
}
