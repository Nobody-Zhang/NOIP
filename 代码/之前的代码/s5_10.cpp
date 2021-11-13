#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,i;
	double b,max=-10000000000;
	cin>>a;
	for(i=1;i<=a;i++)
	{
		cin>>b;
		if(b>=max)
		max=b;
	}
	cout<<"max="<<max;
	return 0;
}
