#include<bits/stdc++.h>
using namespace std;
int w[11],n[11],m;
bool f[4005];
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)
	 cin>>w[i];//砝码重量 
	for(int j=1;j<=m;j++)
	 cin>>n[j];//砝码最多的个数 
	 f[0]=true;
	for(int i=1;i<=m;i++)
	 for(int k=1;k<=n[i];k++)
	  {
	  	for(int j=4000;j>=w[i];j--)
	  	 if(f[j-w[i]]==true)
	  	  f[j]=true;
	  	//f[j]=f[j]||f[j-w[i]];
	  }
	int all=0;
	for(int i=1;i<=4000;i++)
	 all+=f[i];
	cout<<all<<endl;
	return 0;
}
