#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int num=20;//�ܹ������� 
int n[22];//��ô��� 
int used[22];//�Ѿ��ù������� 
int c[55];//�������� ��0��������
long long total; 
void p()//����������
{
	for(int i=2;i<=50;i++)
	 for(int j=2;1;j++)
	 {
	 	if(i*j>50) break;
	 	c[i*j]++;
	 }
} 
int pd(int x,int y)
{
	int i=x+y;
	if(c[i]==0)
	return 1;
	return 0;
}
void dfs(int j)// j��ѭ���Ĵ��� 
{
	if(j>num)
	if(pd(n[20],n[1])==1)
	{
		for(int i=1;i<=20;i++)
		cout<<n[i]<<" ";
		cout<<"\n";
		total++;
		return;
	}
	for(int k=1;k<=20;k++)
	if(pd(n[j-1],k)==1&&used[k]==0)
	{
		n[j]=k;
		used[k]=1;
		dfs(j+1);
		used[k]=0;
	}
}
int main()
{
	c[0]=c[1]=1;
	p();
	dfs(1);
	cout<<total;
	return 0;
}
