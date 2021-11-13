#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int num=20;//总共的数字 
int n[22];//怎么输出 
int used[22];//已经用过的数字 
int c[55];//打表存素数 是0的是素数
long long total; 
void p()//求素数函数
{
	for(int i=2;i<=50;i++)
	 for(int j=2;1;j++)
	 {
	 	if(i*j>50) break;
	 	c[i*j]++;
	 }
} 
int pd(int x,int y)
{
	int i=x+y;
	if(c[i]==0)
	return 1;
	return 0;
}
void dfs(int j)// j是循环的次数 
{
	if(j>num)
	if(pd(n[20],n[1])==1)
	{
		for(int i=1;i<=20;i++)
		cout<<n[i]<<" ";
		cout<<"\n";
		total++;
		return;
	}
	for(int k=1;k<=20;k++)
	if(pd(n[j-1],k)==1&&used[k]==0)
	{
		n[j]=k;
		used[k]=1;
		dfs(j+1);
		used[k]=0;
	}
}
int main()
{
	c[0]=c[1]=1;
	p();
	dfs(1);
	cout<<total;
	return 0;
}
