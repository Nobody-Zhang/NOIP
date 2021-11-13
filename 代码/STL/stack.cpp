#include<bits/stdc++.h>
using namespace std;
stack<int> st;//定义一个栈
int all; 
int main()
{
	for(int i=1;i<=8;i++)
	 st.push(i);//压栈 
	int tp=st.top();//读取栈顶元素 
	cout<<"栈顶元素是"<<tp<<endl;
	for(int i=1;i<=3;i++)
	 st.pop();//弹出栈顶元素 
	cout<<st.top()<<" "<<st.top()<<endl;
	bool y=st.empty();//判断是否为空 
	if(y) cout<<"空"<<endl;
	else cout<<"非空"<<endl;
	cout<<"当前栈里面还有"<<st.size()<<"个元素"<<endl;
	return 0;
 } 
