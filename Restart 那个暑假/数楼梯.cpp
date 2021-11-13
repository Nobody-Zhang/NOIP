#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001][2000];
void add(int x)//要计算a[x],这个地方是高精度
{
	for(int i=1;i<=a[x-1][0];i++)
	{
		a[x][i]=a[x][i]+a[x-1][i]+a[x-2][i];
		if(a[x][i]>=10) {
			a[x][i+1]+=1;
			a[x][i]-=10;
		}
	}
	if(a[x][a[x-1][0]+1]) a[x][0]=a[x-1][0]+1;
	else a[x][0]=a[x-1][0];
	return;
}
void print()
{
	for(int i=a[n][0];i>=1;i--)
		printf("%d",a[n][i]);
	return;
}
int main()
{
	scanf("%d",&n);
	a[0][0]=1;
	a[1][1]=1,a[1][0]=1;//a[x][0]储存a[x]的位数
	a[2][1]=2,a[2][0]=1;
	for(int i=3;i<=n;i++)
		add(i);
	print();
	return 0;
}