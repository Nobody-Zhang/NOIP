#include<bits/stdc++.h>
using namespace std;
int m,n,as[1100][31],a[31],b[31];
//as��i����j����ǰ��i������Ϊj�Ŀռ������Ʒ�����ֵ 
int main()
{
	cin>>m>>n;//m����������n���ܹ��ж��ٵ���Ʒ 
	for(int i=1;i<=n;i++)
	 cin>>a[i]>>b[i];//a������b��ֵ 
	for(int i=1;i<=n;i++)//�ӵ�һ���������� 
	 for(int v=m;v>0;v--)//��v��ʼ����ѡ 
	  if(a[i]<=v)//��ʾ�ܹ�װ���� 
	   as[i][v]=max(as[i-1][v],as[i-1][v-a[i]]+b[i]);
	  else as[i][v]=as[i-1][v];
	cout<<as[n][m];
	return 0;
}
/*
10 4
2 1
3 3
4 5
7 9
*/
