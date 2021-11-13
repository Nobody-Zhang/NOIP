#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int as;
void digit(int a,int b)
{
	if(b==0)
	{
		as=a%10;
		return;
	}
	 a=a/10;
	digit(a,b-1);
}
int main()
{
	int m,n;
	cin>>m>>n;
	digit(m,n-1);
	cout<<as;
	return 0;
}
