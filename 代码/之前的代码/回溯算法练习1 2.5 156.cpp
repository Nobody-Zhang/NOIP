#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
char a[25][25];//�����ַ���
int used1[91],used2[25][25];
//used1���ù�����ĸ��used2���߹��ķ��� 
//A��65��Z��90 ��used�ַ���� 65-90
int ud[4]={1,-1,0,0};//������ô�� 
int lr[4]={0,0,1,-1};//������ô�� 
int max=0,m,n,l;//��������� m��n�еĵ�ͼ 
void search(int roe,int col,int u)//search���������� 
//roe���ڵ��У�col�У�u��
{
	l=u;
	if(l>max) max=l;
	//��ֹ����������
	for(int i=0;i<=3;i++)
	{
		int x1=roe+ud[i];
		int y1=col+lr[i];
		if(x1>0&&x1<=m&&y1>0&&y1<=n&&used1[a[x1][y1]]==0&&used2[x1][x2]==0)
		{
			used1[a[x1][y1]]=1;
			used2[x1][x2]=1;
			search(x1,y1,u+1);
			used1[a[x1][y1]]=0;
			used2[x1][x2]=0;
		}
			
	} 
} 
int main()//������ 
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)//�����ַ�
	 for(int r=1;r<=n;r++)
	 cin>>a[i][r];
	used2[1][1]=1;
	used1[a[1][1]]=1;
	search(1,1,1);
	cout<<max;
	return 0;
}
