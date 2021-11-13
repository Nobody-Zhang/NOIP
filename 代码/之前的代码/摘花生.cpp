#include<bits/stdc++.h>
using namespace std;
int m,in[101][101],f[101][101],x,y;
int main()
{
	cin>>m;
	while(m)
	{
		memset(in,0,sizeof(in));
		memset(f,0,sizeof(f));
		cin>>x>>y;
		for(int i=1;i<=x;i++)
		 for(int j=1;j<=y;j++)
		  cin>>in[i][j];
		for(int i=1;i<=x;i++)
		 {
		 	for(int j=1;j<=y;j++)
		 	 f[i][j]=max(f[i-1][j],f[i][j-1])+in[i][j];
		 }
		cout<<f[x][y]<<endl;
		m--;
	}
	return 0;
}
