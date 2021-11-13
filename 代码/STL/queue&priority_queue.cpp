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
		q.push(in);//队尾入列 
	}
	int to=q.front();//读取队首元素 
	int tal=q.back();//读取队尾元素 
	cout<<"队首元素"<<to<<endl<<"队尾元素"<<tal<<endl;
	q.pop();//队首出列 
	cout<<"队首出列"<<endl;
	if(q.empty()==true)//队不为空 
	 cout<<"空"<<endl;
	else
	 cout<<"非空"<<endl;
	cout<<"队首"<<q.front()<<endl;
	int size=q.size();
	cout<<"大小"<<size<<endl;
	return 0;
} 
