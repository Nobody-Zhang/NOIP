#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a,b,c,d,e,f;
	scanf("%lf%lf%lf",&a,&b,&c);
	e=sqrt(b*b-4*a*c);
	d=(-b+e)/2/a;
	f=(-b-e)/2/a;
	printf("x1=%0.4lf,x2=%0.4lf",d,f);
	return 0;
}
