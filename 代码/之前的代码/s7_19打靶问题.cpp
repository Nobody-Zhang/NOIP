#pragma GCC optimize(2)//���������Ż� 
#include<bits/stdc++.h>//����ͷ 
int a[15],total;//����aΪ©����total�ܷ������� 
using namespace std;//��Ҳ��֪����ʲô 
void dfs(int i,int rest)//�ڼ�ǹ<=10������©rest�� 
{
	if(i==11)//�ڹ涨����©��ʮ�������ǵõ�90�� 
	{
		if(rest==0)
		{
			for(int o=1;o<=10;o++)
			printf("%d ",10-a[o]);
			cout<<"\n";
			total++;//��ӡ��ô�� 
		  
		}
	 return;
	}
	for(int k=0;k<=10;k++)
	 {
	 		a[i]=k;
			 dfs(i+1,rest-k);
	 	
	 }
}
int main()
{
	dfs(1,10);
	cout<<total;
	return 0;
}
