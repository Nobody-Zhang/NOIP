#include<bits/stdc++.h>
using namespace std;
int w[205],c[205],f[205][99999],r[205][99999],v,m;
void dfs(int a,int b)//a�ǵڼ�����b�ǵ�ǰ�õĿռ� 
{
	if(a==0||b==0) return;
	if(r[a][b]==0) dfs(a-1,b);
	if(r[a][b]!=0)
	{
		dfs(a-1,b-c[a]);
		cout<<a<<endl;
	}
}
int main()
{
	cin>>m>>v;//��������ٵ���Ʒ���ܹ��ж��ٵĿռ� 
	for(int i=1;i<=m;i++)
	 cin>>w[i]>>c[i];//��������ÿ�������ͼ�ֵ�Ƕ��� 
	for(int i=0;i<=205;i++)
	 for(int j=0;j<=99999;j++)
	  f[i][j]=-2002545;
	for(int i=0;i<=205;i++)
	 f[i][0]=0;
	for(int i=1;i<=m;i++)
	 {
	 	
	 	for(int j=v;j>=0;j--)
	 {
	 	if(f[i-1][j]<f[i-1][j-w[i]]+c[i]&&f[i-1][j-w[i]]+c[i]>0)
	 	{
	 		f[i][j]=f[i-1][j-w[i]]+c[i];
	 		r[i][j]=1;
	 	}
	 	if(f[i-1][j]>f[i-1][j-w[i]]+c[i]&&f[i-1][j]>0)
		f[i][j]=f[i-1][j];
	 }
	 }
	 
	if(f[m][v]<0) cout<<"never!";
	else
	{
		cout<<f[m][v]<<endl;
		dfs(m,v);
	}
	return 0;
}
