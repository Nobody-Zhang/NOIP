#include<bits/stdc++.h>
using namespace std;
/*int i[12];//能取到那些数
int in;//in是输入的数
long long total;//总共的 
void dfs(int m){
	total++;
	for(int j=1;j<=m/2;j++)
	dfs(j);
}
int main()
{
	cin>>in;
	dfs(in);
	cout<<total;
	return 0;
}*/
int in;
long long a[1500002];
int main()
{
	int m;
	cin>>m;
	a[1]=1;
	for(int i=2;i<=m+1;i++)
	{
		if(i%2==0) a[i]=a[i/2]+a[i-1];
		else a[i]=a[i-1];
	}
	cout<<a[m];
	return 0;
}
