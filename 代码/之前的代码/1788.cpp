#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
long long in[1000001],a[1000001],out[1000001]; 
long long dfs(int i)
{
	if(a[i]!=0) return a[i];
	else if(i==1) return a[1]=1;
	else if(i==2) return a[2]=2;
	else if(i>=3) return a[i]=(dfs(i-2)%32767+2*dfs(i-1)%32767)%32767;
}
int main()
{
	int m;
	cin>>m;
	for(int u=1;u<=m;u++)
	{
		cin>>in[u];
		out[u]=dfs(in[u]);
	}
	for(int u=1;u<=m;u++)
	cout<<out[u]<<"\n";
	return 0;
}
