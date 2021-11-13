#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i=1,t=1;
	double s=0;
	while (1.0/i>=pow(10,-6))
	{
		s=s+1.0/i*t;
		t=-t;
		i=i+2;
	}
	printf("%.8lf",4*s);
	return 0;
}
