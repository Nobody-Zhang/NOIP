#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=40-i;j++)
		printf(" ");
		for (j=1;j<=2*i-1;j++)
		printf("*");
		printf("\n");
	}
	n--;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=39-n+i;j++)
		printf(" ");
		for (j=1;j<=2*n+1-2*i;j++)
		printf("*");
		printf("\n");
	}
	return 0;
}
