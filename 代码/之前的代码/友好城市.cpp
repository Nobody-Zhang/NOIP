#include<bits/stdc++.h>
using namespace std;
int mp[5001][3],m,maxx[5001];
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)
	 {
	 	cin>>mp[i][1]>>mp[i][2];
	 	if(mp[i][1]>mp[i][2])
	 	 swap(mp[i][1],mp[i][2]);
	 }
	for(int i=1;i<=m;i++)
	 for(int j=i;j<=m;j++)
	  if(mp[i][1]>mp[j][1]||(mp[i][1]==mp[j][1]&&mp[i][2]>mp[j][2])) 
	   swap(mp[i][1],mp[j][1]),swap(mp[i][2],mp[j][2]);	
	maxx[m]=1;
	for(int i=m-1;i>=1;i--)
	{
		for(int j=i+1;j<=m;j++)
		 if((mp[i][2]<=mp[j][1]||mp[i][2]<=mp[j][1])&&maxx[i]<maxx[j])
		  maxx[i]=maxx[j];
		maxx[i]++;
	}
	int maxxx=0;
	for(int i=1;i<=m;i++)
	 if(maxxx<maxx[i]) maxxx=maxx[i];
	cout<<maxxx;
	return 0;
}
