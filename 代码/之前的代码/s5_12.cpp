#include<bits/stdc++.h>
int main()
{
	int a0=0,a1=1,a2,i;
	printf("%d,%d",a0,a1);
	for(i=2;i<=20;i++)
	{
		a2=a0+a1;
		printf(",%d",a2);
		a0=a1;
		a1=a2;
	}
	return 0;
}
