#include<bits/stdc++.h>
using namespace std;
#define maxp 20015
int m[8][8]={{},
{0,0,5,2,0,0,0,0},
{0,0,0,0,3,2,0,0},
{0,0,0,0,0,7,4,0},
{0,0,0,0,0,0,0,4},
{0,0,0,0,0,0,0,3},
{0,0,0,0,0,0,0,5},
{}
};//7*7
int g[8],path[8];
int main()
{
	g[7]=0,path[7]=0;
	for(int i=1;i<=6;i++)
	 g[i]=maxp;
	for(int i=6;i>=1;i--)
	 for(int j=i+1;j<=7;j++)
	  if(m[i][j]!=0&&g[i]>g[j]+m[i][j])
	   g[i]=m[i][j]+g[j],path[i]=j;
	cout<<g[1]<<endl;
	for(int i=1;i<=7;i++)
	 {
	 	if(path[i]==path[i+1])break;
	 	cout<<path[i]<<" ";
	 }
	cout<<"7";
	return 0;
}
