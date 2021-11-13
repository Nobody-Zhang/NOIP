#include<bits/stdc++.h>
using namespace std;
double S;
double er(double a,double b,double c)
{
	int v;
	v=a*b*c;
	S=2*(a*b+b*c+c*a);
	return v;
} 
int main()
{
	double d,e,f,V;
	cin>>d>>e>>f;
	V=er(d,e,f);
	printf("V=%.2lf S=%.2lf",V,S);
	return 0;
}
