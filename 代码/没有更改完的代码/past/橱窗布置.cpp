#include<bits/stdc++.h>
using namespace std;
int f,v,in[101][101],f1[101][101],wa[101][101],as[101];//前几个花瓶放入前几朵几朵花值最大 
int main()
{
	cin>>f>>v;//f是花束数量，v是花瓶数量 
	for(int i=1;i<=f;i++)
	 for(int j=1;j<=v;j++)
	  cin>>in[i][j];
	for(int i=1;i<=v-f+1;i++)
	 f1[1][i]=in[1][i];
	for(int i=2;i<=f;i++)
	 for(int j=i;j<=v-f+1;j++)
	  for(int k=i-1;k<=j-1;k++)
	   if(f1[i-1][k]+in[i][j]>f1[i][j])
	    {
	    	f1[i][j]=f1[i-1][k]+in[i][j];
	    	wa[i][j]=k;
	    }
	int maxx=-20000001,k;
	for(int i=f;i<=v;i++)
	 if(maxx<f1[f][i])
	  maxx=f1[f][i],k=i;
	for(int i=1;i<=f;i++)
	{
		as[i]=k;
		k=wa[f-i+1][k];
	}
	cout<<maxx<<endl;
	for(int i=f;i>=2;i--)
	 cout<<as[i]<<" ";
	cout<<as[1]<<endl;
	return 0;
}
