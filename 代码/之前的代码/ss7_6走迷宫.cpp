#pragma GCC optimize(2)//���������Ż� 
#include<bits/stdc++.h>//����ͷ
using namespace std;//...
int mp[12][12],used[12][12],total,m,n;
int x[4]={0,0,1,-1},y[4]={1,-1,0,0};
void dfs(int i,int u,int k)//iΪ�У�uΪ�У�yΪ�ڼ��� 
{
	if(i==m&&u==n)//��������
	 {
	 	total++;//����+1 
	    return; //���� 
	 }
	for(int l=0;l<=3;l++) 
	{
		int x1=i+x[l];
		int y1=u+y[l];
		if(x1>=1&&y1>=1&&x1<=m&&y1<=n&&mp[x1][y1]==1&&used[x1][y1]==0)
		{
			//mp[x1][y1]=0;
			used[x1][y1]=1;
			dfs(x1,y1,k+1);
			//mp[x1][y1]=1;
			used[x1][y1]=0;
		} 
	}
}
int main()
{
	cin>>m>>n;
	for(int a=1;a<=m;a++)
	 for(int b=1;b<=n;b++)
	  cin>>mp[a][b];
	used[1][1]=1;
	dfs(1,1,1);
	cout<<total;
	return 0;
}
