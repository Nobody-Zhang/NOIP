#include<bits/stdc++.h>
using namespace std;
long long f(int i,int j){//i�����֣�j������ 
	if((i<j)||(j==0)) return 0;
	if((i==j)||(j==1)) return 1;
	return f(i-1,j-1)+j*f(i-1,j);
}
int main(){
	int m,n;
	cin>>m>>n;//m����������ָ�n������
	long long as=f(m,n);
	cout<<as;
	return 0; 
}
