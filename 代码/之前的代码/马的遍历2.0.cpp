#include<bits/stdc++.h>
using namespace std;
int m,n;//Ŀ��λ�� (m,n)
int a[500][500];//�ƶ�·��
int q[4]={1,2,1,2};//�����ƶ� 
int p[4]={2,1,-2,-1};//�����ƶ� 
int total;
void pr()//��ӡ���� 
{
	cout<<"0,0";
	for(int i=1;i<=m;i++)
	 for(int j=0;j<=n;j++)
	 if(a[i][j]!=0)
	 	cout<<"->"<<i<<","<<j;
	 cout<<"\n";
	 total++;
}
void dfs(int i,int j)//�������� 
//��ǰλ���ǣ�i��j�� 
{
	if(i==m)//���պõ�ʱ����� 
	{
		if(j==n)
		pr();
		return;
	}
	//if(i==m+1) return;
	for(int w=0;w<=3;w++)
	{
		int x1=i+q[w];
		int y1=j+p[w];
		if(x1>=0&&y1>=0&&x1<=m&&y1<=n)
		{
			a[x1][y1]=1;
			dfs(x1,y1);
			a[x1][y1]=0;
		}
	}
}
int main()//������ 
{
	cin>>m>>n;
	a[0][0]=1;
	dfs(0,0);
	cout<<"total="<<total;
	return 0; 
}
