#include<bits/stdc++.h>
using namespace std;
int f(int m,int n)
{
	if(m==1||n==1||m==0) return 1;
	else if(m<n) return f(m,m);//ʣ������Ӳ�Ҫ 
	else return f(m-n,n)+f(m,n-1); 
	/*f(m-n,n)��ÿ�����Ӹ���һ������� 
	f(m,n-1)��������һ������û�зŵ����*/
}
int main()
{
	int k,h,g;
	cin>>k;
	for(int i=1;i<=k;i++)
	 {
	 	cin>>h>>g;
	 	cout<<f(h,g)<<"\n";
	 }
	 return 0;
}
