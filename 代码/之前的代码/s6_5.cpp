#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a[2][3]={{1.3,2.1,3.9},{4.5,5.3,6.7}},b[3][2];
	int i,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		
			printf("%.1lf ",a[i][j]);
		
			printf("\n");
		
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		b[j][i]=a[i][j];
	}
	for(j=0;j<3;j++)
	{
		for(i=0;i<2;i++)
		{
		
		printf("%.1lf ",b[j][i]);
		}
			printf("\n");
	
	}
		
		return 0;
		
}
