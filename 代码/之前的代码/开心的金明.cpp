#include<bits/stdc++.h>
using namespace std;
int v[26],w[26],m,n,f[50001];
int main()
{
	cin>>m>>n;//m��Ǯ����n�Ǵӹ��ж��� 
	for(int i=1;i<=n;i++)
	 cin>>v[i]>>w[i];
	for(int i=1;i<=n;i++)
	 for(int j=m;j>=v[i];j--)
	  f[j]=max(f[j],f[j-v[i]]+w[i]*v[i]);
	cout<<f[m];
	return 0;
}
