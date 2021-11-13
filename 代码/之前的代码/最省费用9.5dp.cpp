#include<bits/stdc++.h>
#define mo 2333333
using namespace std;
int in[100001],m,mp[101][101],s[100001];
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=m;j++)
	  	cin>>mp[i][j];
	for(int i=1;i<=m-1;i++)
	 in[i]=mo;
	for(int i=m-1;i>=1;i--)
	 for(int j=m;j>=i+1;j--)
	  if(mp[i][j]!=0&&in[i]>in[j]+mp[i][j])
	  {
	  	in[i]=mp[i][j]+in[j];
	  	s[i]=j;
	  }
	cout<<"minlong="<<in[1]<<endl;
	int i=1;
	while(i!=0)
	{
		cout<<i<<" ";
		i=s[i];
	}
}
