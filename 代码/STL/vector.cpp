#include<bits/stdc++.h>
//#include<vector>
using namespace std;
vector<int> v;//长度可以变化的容器 
//vector<int> a[100];//二维 
int all;
void test_out()
{
	for(vector<int>::iterator it=v.begin();it!=v.end()/*取末尾的下一个元素地址*/;it++)//定义迭代器并访问 
	 cout<<*it<<" ";
}
void test_in()
{
	for(int i=1;i<=all;i++)
	{
		int j;
		cin>>j;
		v.push_back(j);//在最后面加一个元素 
	}
}
int main()
{
	cin>>all;
	test_in();
	//v.resize(8);//重设数组大小 
	//v.pop_back();//删除最末端元素 
	//v.clear();//清空所有元素 
	//v.insert(v.begin()+3,6);//插入元素，在v[3]个插入“6” 
	//v.erase(v.begin()+2);//删除v[2] 
	//v.erase(v.begin()+1,v.begin()+4);//删除v[ [1,4) ]的所有元素（1，2，3） 
	int sz=v.size();//获取vector大小 
	cout<<sz<<endl;//输出大小 
	test_out();
	return 0;
 } 
