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
{//注意，这里是从A到i点的最短路径 
	for(int i=2;i<=7;i++)
	 {
	 	g[i]=maxp;
		for(int j=1;j<=i-1;j++)
		 if(m[j][i]!=0&&g[i]>g[j]+m[j][i])
		  g[i]=g[j]+m[j][i],path[i]=j;
	 }
	 cout<<g[7]<<endl;
	for(int i=2;i<=7;i++)
	 {
	 	if(path[i]==path[i-1]) break;
	 	cout<<path[i]<<" ";
	 }
	return 0;
}
