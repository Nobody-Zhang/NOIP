#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int e;//��e���������� 
char in[101][101][101];//��һ���ǵڼ�������
//�ڶ�������
//���������� 
int used[101][101][101];
int mb[101][4];//Ŀ���
//[1,2]����ʼλ��
//[3,4]����ֹλ�� 
int a[101];//�ж��ٸ� ��a[?]*a[?] 
int lf[4]={1,-1,0,0};
int ud[4]={0,0,1,-1};//������������ 
int bj;//���ǣ�����������yes ��Ȼ���no 
void dfs(int i,int j,int k)
//�ӣ�i��j����ʼ���� �ǵ�k�� 
{
	 if(i==mb[k][3]&&j==mb[k][4])//���������յ�
	  {
	  	bj=1;
	  	return;
	  }
	 for(int l=0;l<=3;l++)
	 //������ͼ�����ǲ����߹���
	 {
	 	if(bj==1) break;
	 	int x=i+lf[l];
	 	int y=j+ud[l];//������������ 
	 	if(x>0&&y>0&&x<=a[k]&&y<=a[k])//�ڱ߽�֮��
		{
			if(used[k][x][y]==0&&in[k][x][y]=='.')//û���߹� 
			{
				used[k][x][y]=1;//��� 
				dfs(x,y,k);//���� 
				used[k][x][y]=0;//������ 
			}
		}
	 } 
}
int main()
{
	cin>>e;
//	for(int i=1;i<=e;i++)
	 //cin>>a[i];//�����Ǽ�*���ķ���
	for(int i=1;i<=e;i++)//�ڼ�������
	{
		cin>>a[i];//����ڼ��������еĴ�С
		//����n*n�е�n 
	 	for(int j=1;j<=a[i];j++)
	 	 for(int r=1;r<=a[i];r++)
	 	  cin>>in[i][j][r];//�����ͼ 
	 	for(int j=1;j<=4;j++)
	 	{
	 		cin>> mb[i][j];//������ʼ��andĿ��� 
	 		mb[i][j]+=1;//��ĿҪ�� 
	 	}
	}
	for(int i=1;i<=e;i++)
	 {
	 	bj=0;//�����0 
	 	used[i][mb[i][1]][mb[i][2]]=1;
		 // ����עΪ1 ��ʾ�߹� 
	 	dfs(mb[i][1],mb[i][2],i);//���� 
	 	if(bj==0) cout<<"NO\n";//��û�������ʱ 
	 	else cout<<"YES\n";//���˱�Ǿ����YES 
	 }
}
