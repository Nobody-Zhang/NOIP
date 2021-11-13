#include<bits/stdc++.h>
using namespace std;
int max2(int a,int b)
{
	if(a>b) return a;
	if(a<=b) return b;
}
int max4(int a,int b,int c,int d)
{
	max2(max2(a,b),max(c,d));
}
int main()
{
	int a,b,c,d,max;
	cin>>a>>b>>c>>d;
	max=max4(a,b,c,d);
	cout<<max;
}
