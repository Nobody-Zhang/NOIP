#include<bits/stdc++.h>
using namespace std;
int m,n;//�ܹ�m���ˣ�n�Գ�й�ϵ 
int w[3001][3001];//��ʾ�Ƿ��ǳ�� 
int out[3001];//�Ƿ�ѡ 
int s[3001];//��ǰѡ����� 
int as;//��ʾ���ֵ 
void pr()
{
	cout<<as<<endl;
	 for(int j=1;j<=m;j++)
	cout<<out[j]<<" ";
}
void dfs(int x,int y)//x��ѡ�����ٸ��ˣ�y�ǵ�ǰѡ���˵ĸ��� 
{
	if(x>m) 
	{
		if(as<y) 
		{
			as=y;
			memset(out,0,sizeof(out));//������0 
			for(int i=1;i<=m;i++)
		 	out[i]=s[m];
		}
		return;
	}
	if(as<y){
		as=y;
		memset(out,0,sizeof(out));//������0 
		for(int i=1;i<=m;i++)
		 out[i]=s[m];
	}
	for(int i=x+1;i<=m;i++)
	{
		s[i]=1,y=y+1;
		dfs(i,y);
		s[i]=0,y=y-1;
	}
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		int l,k;
		cin>>l>>k;
		w[l][k]=1,w[k][l]=1;//���ж���� 
	}
	dfs(1,0);
	pr();
	return 0;
}
