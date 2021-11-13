//用的是导游程序，可能会有些累赘 
#include<bits/stdc++.h>
using namespace std;
int z[20];
int as;
int n;
int a[20][20];
int k[20];
void pr()
{
	for(int i=1;i<=n;i++)
	 {
	 	cout<<"J"<<i<<" "<<k[i]<<endl;
	 }
}
void dfs(int i,int p)
{
	if(i>n)
	{
		if(p<as) 
		{
			as=p;
			for(int j=1;j<=n;j++)
			k[j]=z[j];
		}
		return;
	}
	if(p>=as) return;
	for(int j=1;j<=n;j++)
	if(z[j]==0)
	{
		z[j]=i;
		dfs(i+1,p+a[i][j]);
		z[j]=0;
	}
} 
int main()
{


	cin>>n;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	  {
	  	cin>>a[i][j];
	  	a[i][j]=1000-a[i][j];
	  }
	as=2000000;
	dfs(1,0);
	pr();
	return 0;
}
