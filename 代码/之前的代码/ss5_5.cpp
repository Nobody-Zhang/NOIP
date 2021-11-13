#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,s,d=1000,y;
	for(a=1;a<=d;a++)
	{
		s=0;
		for(b=1;b<=a-1;b++)
		{
		y=a%b;
		if(y==0)
			s=b+s;
		}
		if(s==a)
			cout<<s<<" ";	
	}
	return 0;
}
