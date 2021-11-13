#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
long long a[1000];
int p[1000];
int dfs(int i)
{
	int l;
	if(i==1||i==2) return 1;
	if(i>=3)
	 return dfs(i-2)+dfs(i-1);
}
int main()
{
	int m;
	cin>>m;
	for(int o=1;o<=m;o++)
	 {
	 	cin>>p[o];
	 	a[o]=dfs(p[o]);
	 }
	for(int o=1;o<=m;o++)
	cout<<a[o]<<"\n";
	return 0;
}
