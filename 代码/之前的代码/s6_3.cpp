#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i;
	double a[11],pj=0;
	for(i=1;i<=10;i++)
	{
		scanf("%lf",a+i);
		pj+=a[i];
	}
	pj/=10;
	for(i=1;i<=10;i++)
	{
		printf("%0.2lf ",a[i]-pj);
	}
	return 0;
	
}
