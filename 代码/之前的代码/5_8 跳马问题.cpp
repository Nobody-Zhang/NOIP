#pragma GCC optimize (2)
#include<bits/stdc++.h>
using namespace std;
int as[100][100],r[100][100];
int a[8]={1,2,2,1,-1,-2,-2,-1};
int b[8]={-2,-1,1,2,2,1,-1,-2};
int total=0;
void pr()
{
	total++;
	if(total<=5)
	{
		for(int i=1;i<=5;i++)
		 {
		 	for(int j=1;j<=5;j++)
		 	cout<<as[i][j]<<" ";
		 	cout<<"\n";
		 }
		 cout<<"\n";
	} 
}
void dfs(int i,int j,int q)//��ǰ��i��j�е�q�� 
{
	if(q>25)//��ȫ���������� 
	{
		pr();//��ӡ 
		return;//���� 
	}
	for(int l=0;l<=7;l++)//�����Ƿ��н� 
	{
		int x=a[l]+i;
		int y=b[l]+j;
		if(x>0&&x<=5&&y>0&&y<=5)
		if(as[x][y]==0&&r[x][y]==0)
		{
			r[x][y]=1;
			as[x][y]=q;
			dfs(x,y,q+1);
			as[x][y]=0;
			r[x][y]=0;
		}
	}
}
int main()
{
	as[1][1]=1;
	dfs(1,1,2);
	return 0;
}
