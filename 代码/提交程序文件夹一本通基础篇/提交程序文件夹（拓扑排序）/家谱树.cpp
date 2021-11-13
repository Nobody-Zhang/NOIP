#include<bits/stdc++.h>
using namespace std;
int r[101];//入度 
int c[101];//出度 
int a[101][101];//第几个数后面相连了哪些数 
int as[101],total_as,num;
int main()
{
	int m;
	cin>>m;//输入有多少个数据 
	for(int i=1;i<=m;i++)
	{
		int j;
		do
		{
			cin>>j;
			if(j!=0)
			{
				c[i]++;
				a[i][c[i]]=j;
				r[j]++;
			}
		}while(j!=0);
	}
	for(int i=1;i<=m;i++)
	 if(r[i]==0)
	  as[++total_as]=i;
	do
	{
		int tmp=as[total_as];
		cout<<tmp<<" ";
		total_as--,num++;
		for(int i=1;i<=c[tmp];i++)
		{
			r[a[tmp][i]]--;
			if(r[a[tmp][i]]==0)
			 as[++total_as]=a[tmp][i];
		}
	}while(num!=m);
	return 0;
}
