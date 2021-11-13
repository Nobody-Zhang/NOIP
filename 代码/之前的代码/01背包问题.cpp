#include<bits/stdc++.h>
using namespace std;
int m,n,as[1100][31],a[31],b[31];
//as【i】【j】是前面i件容量为j的空间放入物品的最大值 
int main()
{
	cin>>m>>n;//m是总重量，n是总共有多少的物品 
	for(int i=1;i<=n;i++)
	 cin>>a[i]>>b[i];//a重量和b价值 
	for(int i=1;i<=n;i++)//从第一个往下面试 
	 for(int v=m;v>0;v--)//从v开始向下选 
	  if(a[i]<=v)//表示能够装得下 
	   as[i][v]=max(as[i-1][v],as[i-1][v-a[i]]+b[i]);
	  else as[i][v]=as[i-1][v];
	cout<<as[n][m];
	return 0;
}
/*
10 4
2 1
3 3
4 5
7 9
*/
