#include<bits/stdc++.h>
using namespace std;
int in[1005],m,g[1005],maxx;
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)
	 cin>>in[i];
	g[m]=1;
	for(int i=m-1;i>=1;i--)
	 {
	 	for(int j=i+1;j<=m;j++)
	  	 if(g[i]<g[j]&&in[i]>in[j])
	   	  g[i]=g[j];
	   	g[i]++;
	 }
	for(int i=1;i<=m;i++)
	 if(maxx<g[i]) maxx=g[i];
	cout<<maxx<<endl;
	return 0;
}
