#include<bits/stdc++.h>
using namespace std;
int max(int x,int y)
{
	int z;
	if(x>y) z=x;
	else z=y;
	return z;
}
int main()
{
	int a,b;
	cin>>a>>b;
	int c=max(a,b);
	cout<<c;
	return 0;
}
