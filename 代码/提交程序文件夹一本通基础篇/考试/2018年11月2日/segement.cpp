#include<bits/stdc++.h>
using namespace std;
int all,m;
int x[20001],y[20001];
int main()
{
	freopen("segement.in","r",stdin);
	freopen("segement.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++)
	 {
	 	cin>>x[i]>>y[i];
	 	all=all+y[i]-x[i];
	 }
	 cout<<all*2<<endl;
	 return 0;
}
