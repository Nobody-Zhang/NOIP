#include<bits/stdc++.h>
using namespace std;
int m,n,f[10005],t[10005],w[10005];
int main()
{
	cin>>m>>n;//m���ܹ���ʱ�䣬n���ж�����ҩƷ 
	for(int i=1;i<=n;i++)
	 cin>>t[i]>>w[i];
	for(int i=1;i<=n;i++)
	 for(int j=m;j>=t[i];j--)
	  f[j]=max(f[j],f[j-t[i]]+w[i]);
	cout<<f[m];
	return 0;
}
