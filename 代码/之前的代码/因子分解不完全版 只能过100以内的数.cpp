#include<bits/stdc++.h>
using namespace std;
int p[26]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,63
,67,71,73,79,83,89,97};//�����ļ���
int h[26];//����ÿ���������Ĵ��� 
int kk;
void dfs(int n)
{
	if(n==1) return;
	else{
		for(int i=1;i<=25;i++)
		{
			if(n%p[i]==0)
			{
				h[i]=h[i]+1;
				dfs(n/p[i]);
				break;
			}
		}
	}
}
int main()
{
	int n;
	cin>>n;
	dfs(n);
	for(int i=1;i<=25;i++)
	{
		if(h[i]>=2)//�д����������� 
		{
			cout<<p[i]<<"^"<<h[i];
			kk=i;
			break;
		}
		if(h[i]==1)
		{
			cout<<p[i];
			kk=i;
			break;
		}
		
	}
	for(int i=kk+1;i<=25;i++)
	{
		if(h[i]>=2)//�д����������� 
		cout<<"*"<<p[i]<<"^"<<h[i];
		if(h[i]==1)
		cout<<"*"<<p[i];
	}
}
