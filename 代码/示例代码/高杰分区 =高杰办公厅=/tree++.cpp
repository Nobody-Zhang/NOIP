#include<bits/stdc++.h>
using namespace std;

string s1,s2;
int n=-1;
void calc(int l2,int r){//l1��s1�ҵ���㣬l2��r��ͬ�����˹��������� 
    cout<<n<<" "<<l2+1<<" "<<r+1<<endl; 
	n++;
	int m=s2.find(s1[n]);//��һ�α����ҵ����ڵ� 
	 calc(l2,m-1);//����������r=m-1�����Ӹ��ڵ������ 
	  calc(m+1,r);//��������
	//����������û���꣬�����ҷ�ͷ�ң������˾���չ 
	//��������if�ǻ��಻��ͻ�� 
	cout<<s1[n];
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	cin>>s1>>s2;
	calc(0,s2.length()-1);//�տ�ʼ����s1��ͷ�ң�������Χ��δ��С 
	return 0;
}
