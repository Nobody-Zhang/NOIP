#include<bits/stdc++.h>
using namespace std;
stack<int> st;//����һ��ջ
int all; 
int main()
{
	for(int i=1;i<=8;i++)
	 st.push(i);//ѹջ 
	int tp=st.top();//��ȡջ��Ԫ�� 
	cout<<"ջ��Ԫ����"<<tp<<endl;
	for(int i=1;i<=3;i++)
	 st.pop();//����ջ��Ԫ�� 
	cout<<st.top()<<" "<<st.top()<<endl;
	bool y=st.empty();//�ж��Ƿ�Ϊ�� 
	if(y) cout<<"��"<<endl;
	else cout<<"�ǿ�"<<endl;
	cout<<"��ǰջ���滹��"<<st.size()<<"��Ԫ��"<<endl;
	return 0;
 } 
