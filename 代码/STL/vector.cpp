#include<bits/stdc++.h>
//#include<vector>
using namespace std;
vector<int> v;//���ȿ��Ա仯������ 
//vector<int> a[100];//��ά 
int all;
void test_out()
{
	for(vector<int>::iterator it=v.begin();it!=v.end()/*ȡĩβ����һ��Ԫ�ص�ַ*/;it++)//��������������� 
	 cout<<*it<<" ";
}
void test_in()
{
	for(int i=1;i<=all;i++)
	{
		int j;
		cin>>j;
		v.push_back(j);//��������һ��Ԫ�� 
	}
}
int main()
{
	cin>>all;
	test_in();
	//v.resize(8);//���������С 
	//v.pop_back();//ɾ����ĩ��Ԫ�� 
	//v.clear();//�������Ԫ�� 
	//v.insert(v.begin()+3,6);//����Ԫ�أ���v[3]�����롰6�� 
	//v.erase(v.begin()+2);//ɾ��v[2] 
	//v.erase(v.begin()+1,v.begin()+4);//ɾ��v[ [1,4) ]������Ԫ�أ�1��2��3�� 
	int sz=v.size();//��ȡvector��С 
	cout<<sz<<endl;//�����С 
	test_out();
	return 0;
 } 
