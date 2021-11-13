#include<bits/stdc++.h>
using namespace std;
int mod(int n)
{
	if(n==0)return 1;
	else return mod(n-1)*(n%2012)%2012;
}
int main()
{
	int u,m;
	cin>>u;
	m=mod(u);
	cout<<m;
}
