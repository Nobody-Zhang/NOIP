#include<bits/stdc++.h>
using namespace std;
int gys(int a,int b)
{
	if(b==0) return a;
	return gys(b,a%b);
}
int main()
{
	int i,j,m,n;
	cin>>i>>j;
	m=gys(i,j);
	n=i/m*j;
	cout<<m<<" "<<n;
	return 0;
}
