#include<bits/stdc++.h>
using namespace std;
int m,n;
int tong[1000];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int tmp;
		cin>>tmp;
		tong[tmp]++;
	}
	for(int i=1;i<=n;i++)
	if(tong[i]){
		for(int j=1;j<=tong[i];j++)
		 cout<<i<<" ";
	}
	return 0;
}