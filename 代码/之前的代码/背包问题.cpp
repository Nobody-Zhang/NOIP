#include<bits/stdc++.h>
using namespace std;
int a[3][52],m,n,f[52];
int out[52],ou[52];//��ôѡ 
int t,as;//t�ǵ�ǰ�Ľ⣬as�����Ž� 
void dfs(int i,int left)//��i�Σ���ʣleft�� 
{
	if(t+f[i]<as) return;
	//���㵱ǰ�����ֵ���Ϻ���ȫѡ���ﲻ�����Ž⣬����
	//����Ǽ�֦�ĺ��� 
	if(t>as)//��ǰ�Ĵ��ڵ�ǰ���Ž⣬�����Ž��滻�ɵ�ǰ�� 
	{
		as=t;//������ֵ�ķ������뵽answer���� 
		for(int k=1;k<=n;k++)
		out[k]=ou[k];//����ôѡ�����鶨�嵽�������� 
	}
	for(int j=i;j<=n;j++)
	if(left>=a[1][j])//��ʣ�µĿռ仹��װ���������Ʒʱ���� 
	{
		ou[j]=1;//ѡ�����Ʒ 
		t+=a[2][j];//��ǰ�Ľ���� 
		dfs(j+1,left-a[1][j]);//������һ����ô�� 
		ou[j]=0;
		t-=a[2][j];//�ָ� 
	}
}
int main()
{
	cin>>m>>n;//m������n����Ʒ
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=2;j++)
	  cin>>a[j][i];//����ÿ������(1)�ͼ۸�(2)
	for(int i=n;i>=1;i--)
	 f[i]=f[i-1]+a[2][i];//��׺�� �����Ƕ�ȡ�����ֵ 
	dfs(1,m);
	cout<<as<<endl;//������ֵ 
	for(int i=1;i<=n;i++)
	if(out[i]!=0) //Ҫ��ǰ����Ʒ 
	cout<<i<<" ";//������ 
}
