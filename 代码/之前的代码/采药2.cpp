#include<bits/stdc++.h>
using namespace std;
int t,m,f[200001];
int main()
{
	cin>>t>>m;
	for(int i=1;i<=m;i++)
	 {
	 	int x,y;
	 	cin>>x>>y;
	 	for(int j=t;j>=x;j--)
	 	 f[j]=max(f[j],f[j-x]+y);
	 }
	cout<<f[t];
	return 0;
}
