#include<bits/stdc++.h>
using namespace std;
int n,in[10001],j,s;
//n���ж����ƶ�,in��ÿ�Ѷ�����,j��һ�������� 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	 cin>>in[i];
	 j+=in[i];
	}
	j/=n;//��ƽ�� 
	for(int i=1;i<=n;i++)
	 in[i]-=j;//ÿ������ȥƽ���� 
	int i=1,k=n;
	while(in[i]==0&&i<n) i++;//��ǰ���0��ȥ 
	while(in[k]==0&&k>1) k--;//�������0��ȥ 
	while(i<k) 
	{
		in[i+1]+=in[i];//�ѵ�i�����ݼӵ�i+1�� 
		in[i]=0;//��һ�����ﵽƽ���� 
		s++;//�ܲ���+1 
		i++;//��һ�� 
		while(in[i]==0&&i<k) i++;//��������е�0 
	}
	cout<<s<<endl;//����ܹ��ķ����� 
	return 0;
}
