#include<bits/stdc++.h>
using namespace std;
int z[20];//�Ѿ����Ź��ľ���
int as;//������Ϥ��
int n;//n������n������ 
int a[20][20];
void dfs(int i,int p)//i�ǵڼ��Σ�p����Ϥ�̶� 
{
	if(i>n)
	{
		if(p<as) as=p;
		return;
	}
	if(p>=as) return;
	for(int j=1;j<=n;j++)
	if(z[j]==0)
	{
		z[j]=1;
		dfs(i+1,p+a[i][j]);
		z[j]=0;
	}
} 
int main()
{


	cin>>n;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	  {
	  	cin>>a[i][j];
	  	a[i][j]=1000-a[i][j];
	  }
	as=2000000;
	dfs(1,0);
	cout<<1000*n-as;
	return 0;
}
