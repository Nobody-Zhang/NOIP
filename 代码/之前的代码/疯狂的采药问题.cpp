#include<bits/stdc++.h>
using namespace std;
int t,m,s[100005],w[100005],f[500005];
int main()
{
	cin>>t>>m;//t时间，m价值 
	for(int i=1;i<=m;i++)
	 cin>>w[i]>>s[i];
	for(int i=1;i<=m;i++)
	 for(int k=w[i];k<=t;k++)
	  f[k]=max(f[k],f[k-w[i]]+s[i]);
	cout<<f[t];
	return 0;
}
