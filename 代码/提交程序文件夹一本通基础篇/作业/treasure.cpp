//#pragma GCC optimize(2) 
#include<bits/stdc++.h>
using namespace std;
int f[40005],v,m,a[101],b[101],c[101];
//a是价值 b重量 c数量 
int main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	cin>>m>>v;
	for(int i=1;i<=m;i++)
	 cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=m;i++)
	 {
	 	int x=1;
	 	while(c[i]!=0)
	 	{
	 		int jz=a[i]*x,vv=b[i]*x;
	 		for(int j=v;j>=vv;j--)
	 		{
	 			f[j]=max(f[j],f[j-vv]+jz);
			 }
			c[i]-=x;
			if(c[i]<x*2) x=c[i];
			else x*=2;
		 }
		 //for(int k=v;k>=b[i];k--)
	     //f[k]=max(f[k],f[k-b[i]]+a[i]);
	 }//for(int j=1;j<=c[i];j++)
	  
	cout<<f[v];
	return 0;
}/*
4 20
3 9 3
5 9 1
9 4 2
8 1 3

#include<bits/stdc++.h>
using namespace std;
int f[40005],v,ji,m,a[10001],b[10001],c[101],all;
//a是价值 b重量 c数量 
int main()
{
	//freopen("treasure.in","r",stdin);
	//freopen("treasure.out","w",stdout);
	cin>>m>>v;
	for(int i=1;i<=m;i++)
	 cin>>a[i]>>b[i]>>c[i];
	 all=m;
	for(int i=1;i<=m;i++)
	{
		int x=1;
		while(1)
		{
			if(x*2>c[i]) break;
			all++;
			x*=2;
			a[all]=x*a[i],b[all]=x*b[i];
		}
		x*=2;
		all++;
		a[all]=x*a[i],b[all]=x*b[i];
	}
	for(int t=1;t<=all;t++)
	printf("%d\n",a[t]);
	
//	for(int i=1;i<=all;i++)
//	  for(int k=v;k>=b[i];k--)
//	   f[k]=max(f[k],f[k-b[i]]+a[i]);
//	cout<<f[v];
//	return 0;
}*/
