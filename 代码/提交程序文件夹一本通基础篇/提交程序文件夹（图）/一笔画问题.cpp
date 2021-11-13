#include<bits/stdc++.h>
using namespace std;
int m,n,mp[101][101],d[101],start,how[101],how_many;
void find(int i)
{
	for(int j=1;j<=m;j++)
	 if(mp[i][j]==1)
	 {
	 	mp[i][j]=mp[j][i]=0;
	 	find(j);
	 }
	how[++how_many]=i;
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		mp[a][b]=mp[b][a]=1;
		d[a]++;
		d[b]++;
	}
	start=1;
	for(int i=1;i<=m;i++)
	 if(d[i]%2==1)
	  start=i;
	find(start);
	for(int i=1;i<=how_many;i++)
	 cout<<how[i]<<" ";
	cout<<endl;
	return 0;
}
