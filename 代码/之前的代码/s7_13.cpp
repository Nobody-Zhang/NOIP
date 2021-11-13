#include<bits/stdc++.h>
using namespace std;
double f(double x,int n)
{
	if(n==1) return sqrt(x+1);
	return sqrt(n+f(x,n-1));
}
int main()
{
	int b;
	double a,aw;
	cin>>a>>b;
	aw=f(a,b);
	cout<<aw;
	return 0;
}
