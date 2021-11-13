#include<bits/stdc++.h>
using namespace std;
int a[100005]={0};
int f(int n)
{
	if(a[n])
	if(n==1||n==2)return 1;
	return (f(n-1)+f(n-2))%2012;
}
int main()
{
	int i,as;
	cin>>i;
	as=f(i);
	cout<<as;
	return 0;
}
