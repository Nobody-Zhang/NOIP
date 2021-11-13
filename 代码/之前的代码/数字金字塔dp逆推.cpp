#include<bits/stdc++.h>
using namespace std;
int in[1005][1005][4],m;
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=i;j++)
	  {
	  	cin>>in[i][j][1];
	  	in[i][j][2]=in[i][j][1];
	  }
	for(int i=m-1;i>=1;i--)
	 for(int j=1;j<=i;j++)
	  {
	  	if(in[i+1][j][2]>in[i+1][j+1][2])
	  	{
	  		in[i][j][2]+=in[i+1][j][2];
	  		in[i][j][3]=0;
	  	}
	  	else
	  	{
	  		in[i][j][2]+=in[i+1][j+1][2];
	  		in[i][j][3]=1;
	  	}
	  }
	cout<<"max="<<in[1][1][2];
	return 0;
}
