#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,g,s,b,j;
	for(a=2;a<=1000;a++)
	{
		j=a*a;
		g=j%10;
		s=j%100/10;
		b=j%1000/100;
		if(a==100*b+10*s+g||a==10*s+g||a==g) printf("%d ",a);
	}
	return 0;
}
