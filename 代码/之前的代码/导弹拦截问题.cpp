#include<bits/stdc++.h>
using namespace std;
int high[1001],maxx[1001],all,minn;
int k=1;//��ǰ�ĵ�������ϵͳ���� 
int transfor;//��ʾ��ת���� 
int main()
{
	freopen("act.in","r",stdin);
	freopen("act.out","w",stdout);
	while((scanf("%d",&high[++all]))!=EOF);//�������� 
	all=all-1;
	maxx[1]=high[1];
	for(int i=2;i<=all;i++)//������i������ 
	{
		transfor=0;
		for(int j=1;j<=k;j++) 
           //����ȫ��ϵͳ 
		{
			if(maxx[j]>=high[i])
		  	//��ʾ�ܱ�����ϵͳ���� 
			{
				if(transfor==0)//��ʾû���κε���ϵͳ֮ǰ�������� 
				 transfor=j;//��ת��Ϊj 
				else if(maxx[j]<maxx[transfor])// ��ʾ�и��Ž� 
				//Ҳ����˵���и��ȵ�ǰ��ϵͳ���ֵ��С�� 
				 transfor=j;//�������ŷ��� 
			} 
		}
		if(transfor==0)//��ʾ��һ��û��ִ�� 
		//Ҳ����˵��û���κ�ϵͳ������������� 
		{
			k++;//�½�һ������ϵͳ��
			maxx[k]=high[i];//���½���ϵͳ�ܴﵽ�����ֵ����Ϊ��ǰ�ĵ����߶� 	
		} 
		else//��һ��ѭ��ִ�У������ܱ���ǰ�е�ϵͳ���� 
		{
			maxx[transfor]=high[i];//����ϵͳ���������ֵ 
		}
		
	}
	cout<<k<<endl;
	return 0;
}
