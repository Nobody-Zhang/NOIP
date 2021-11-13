#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a[3][4]={{1.289,1.081,1.35,4.28},
					{3.54,5.62,6.38,5.48},
					{6.32,8.37,9.40,8.35}};
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		printf("%.1lf ",a[i][j]);
		printf("\n");
	}
	return 0;
}
