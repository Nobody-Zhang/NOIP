#include<bits/stdc++.h>
using namespace std;
int prime(int b)
{
	int q;
	for(q=2;q*q<=b;q++)
	if(b%q==0) return 0;
	return 1;
}
int main()
{
	int a,b;
	cin>>a>>b;
	for(int i=a;i<=b;i++)
	if(prime(i)&&i!=1) cout<<i<<" ";
	return 0;
}
