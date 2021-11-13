#include<bits/stdc++.h>
using namespace std;
int m,in[101][101];
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=i;j++)
	  cin>>in[i][j];
	for(int i=m-1;i>=1;i--)
	{
		for(int j=1;j<=i;j++)
		 in[i][j]+=max(in[i+1][j],in[i+1][j+1]);
	}
	cout<<in[1][1];
	return 0;
}
