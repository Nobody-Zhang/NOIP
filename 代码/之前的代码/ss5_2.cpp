#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,s,n=1,p;
	double q=0;
	s=1000000;
	for(i=1;i<=s;i++)
	{
		p=2*i-1;
		q+=1.0/p*n;
		n=-n;
	}
	printf ("%0.8lf",4.0*q);
}
