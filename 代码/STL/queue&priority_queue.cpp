#include<bits/stdc++.h>
#include<queue>
using namespace std;
queue<int> q;
int main()
{
	int a;
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		int in;
		cin>>in;
		q.push(in);//��β���� 
	}
	int to=q.front();//��ȡ����Ԫ�� 
	int tal=q.back();//��ȡ��βԪ�� 
	cout<<"����Ԫ��"<<to<<endl<<"��βԪ��"<<tal<<endl;
	q.pop();//���׳��� 
	cout<<"���׳���"<<endl;
	if(q.empty()==true)//�Ӳ�Ϊ�� 
	 cout<<"��"<<endl;
	else
	 cout<<"�ǿ�"<<endl;
	cout<<"����"<<q.front()<<endl;
	int size=q.size();
	cout<<"��С"<<size<<endl;
	return 0;
} 
