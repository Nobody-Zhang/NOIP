#include<bits/stdc++.h>
using namespace std;
int f(int n)
{
	if(n==1||n==2)return 1;
	return f(n-1)+f(n-2);
}
int mod(int u)
{
	int p;
	p=f(u)%2012;
	return p;
}
int main()
{
	int i,as;
	cin>>i;
	as=mod(i);
	cout<<as;
	return 0;
}
