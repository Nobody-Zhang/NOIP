#include<bits/stdc++.h>
int main()
{
	int i,s,n=1;
	double q=0;
	s=10000;
	for(i=1;i<=s;i++)
	{
		q+=1.0/i*n;
		n=-n;
	}
	printf ("%lf",q);
}
