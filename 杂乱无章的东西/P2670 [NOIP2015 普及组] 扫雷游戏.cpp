#include<bits/stdc++.h>
using namespace std;
#define MAXX 102
char mp[MAXX][MAXX];
int ans[MAXX][MAXX];
int xx[9]={0,-1,-1,-1,0,0,1,1,1},yy[9]={0,-1,0,1,-1,1,-1,0,1};
int main()
{
	ios::sync_with_stdio(false);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  {
	  	cin>>mp[i][j];
	  	if(mp[i][j]=='*'){
	  		for(int k=1;k<=8;k++)
	  		 ans[i+xx[k]][j+yy[k]]++;
		  }
	  }
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='*') cout<<"*";
			else cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}