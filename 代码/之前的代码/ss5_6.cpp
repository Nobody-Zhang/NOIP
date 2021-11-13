#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a0=0,a1=1,a2=1,i,a3=0;
	printf("%I64d %I64d %I64d",a0,a1,a2);
	for(i=1;i<=30;i++)
	{
		a3=a0+2*a1+a2;
		a0=a1;
		a1=a2;
		a2=a3;
		printf(" %I64d",a3);
	}
	return 0;
}
