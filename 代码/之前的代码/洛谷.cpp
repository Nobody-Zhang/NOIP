#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int i=0;
	double n=2,x,s=0;
	scanf("%lf",&x);
	while(s<=x)
	{
		s+=n;
		n=n*0.98;
		i++;
	}
	printf("%d",i);
	return 0;
}
