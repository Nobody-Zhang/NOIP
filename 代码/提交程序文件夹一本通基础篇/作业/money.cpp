#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int v,n,m[26];
long long f[20005];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>v>>n;
	for(int i=1;i<=v;i++)
	 cin>>m[i];
	f[0]=1;
	for(int i=1;i<=v;i++)
	 for(int j=m[i];j<=n;j++)
	  f[j]+=f[j-m[i]];
	cout<<f[n];
	return 0;
}
