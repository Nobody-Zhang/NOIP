#include<bits/stdc++.h>
using namespace std;
char a[101][101];//��ͼ��a 
int used[101][101],m,n;//������m��n�У�used��ʾ�߹���λ�� 
int ud[4]={0,0,1,-1};//�������� 
int lr[4]={1,-1,0,0};//��������
int q,w,e,r;//������յ����� 
void dfs(int c,int d,int i)//��ǰ��c��d��i�� 
{
	if(c==e&&d==r) 
	{
		cout<<"YES"<<i;
		return;
	}
	for(int h=0;h<=3;h++)
	 {
	 	int x1=c+ud[h];//����������
		int y1=d+lr[h];//���������� 
	 	if(x1>=0&&y1>=0&&x1<m&&y1<n&&a[x1][y1]=='.'&&used[x1][y1]==0)
	 	{
	 		i++;
	 		used[x1][y1]=1;
	 		dfs(x1,y1,i);
	 		used[x1][y1]=0;
	 	}
	 }
}
int main()
{
	cin>>m>>n;//������m��n��
	int u,o,f;
	for(u=0;u<m;u++)
	 for(o=0;o<n;o++)
	  cin>>a[u][o];//�����ͼ
	cin>>q>>w>>e>>r;//��������յ�����
	dfs(q,w,0);//����
	return 0; 
}
