#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
int Hermite(int n,int x)
{
	if(n==0)
	 return 1;
	if(n==1)
	 return 2*x;
	if(n>1)
	 return 2*x*Hermite(n-1,x)-2*(n-1)*Hermite(n-2,x);
}
int main()
{
	int a,b,as;
	cin>>a>>b;//先输入x然后才是n 
	as=Hermite(b,a);
	cout<<as;
	return 0; 
}
