#include<bits/stdc++.h>
using namespace std;
//bool a[6][6];//ǰ�����ˣ��������� 
int used[6];//��
int u[6];//��
int a[6][6]={{0,0,0,0,0,0},{0,0,0,1,1,0},{0,1,1,0,0,1},
{0,0,1,1,0,0},{0,0,0,0,1,0},{0,0,1,0,0,1}};
/* a[6][6]={{0,0,0,0,0,0},{0,0,1,0,0,0},{0,0,1,1,0,1},
{0,1,0,1,0,0},{0,1,0,0,1,0},{0,0,1,0,0,1}};*/
int re;
int out[6];//��ô���ÿ����ѡʲô 
void pr()
{
	cout<<"answer "<<re<<":"<<endl;
	for(int i=1;i<=5;i++)
	 printf("%d:%c\n",i,out[i]+'A'-1);
}
void dfs(int j)//j�ǵڱ��� 
{
	if(j>5)//�������� 
	{
		re++;
		pr();
		return;	
	}
	for(int i=1;i<=5;i++)//��������ѡ�� 
	if(a[i][j]==1)
	if(used[j]==0&&u[i]==0)// i���ˣ�j���鱾 
	//�����ϲ��ϲ��  �����û��ѡ����
	{
		used[j]=1;//�����ѡ���鱾��
		u[i]=1;
		out[i]=j;//��i����ѡ�˵�j����
		//for(int i=1;i<=5;i++)
		dfs(j+1);//������һ�� 
		u[i]=0;
		used[j]=0; 
	}
}
int main()
{

	/*for(int i=1;i<=5;i++)
	 for(int j=1;j<=5;j++)
	 {
	 	a[i][j]=false;
	 }
	for(int i=1;i<=5;i++)
	 for(int j=1;j<=5;j++)
	  {	  	
	  if(b[i][j]==1) a[i][j]=true;
		else a[i][j]=false;
		  }*/
	dfs(1);
	return 0;
}
