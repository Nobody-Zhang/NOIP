//ц╟ещеепР
#include<bits/stdc++.h>
using namespace std;
int a[11]={0};
int main()
{
	int i,k;
	for(i=1;i<=5;i++)
		scanf("%d",&a[i]);
    //for(i=1;i<=5;i++)
	//	printf("%d ",a[i]);	
		
	for(i=1;i<=4;i++)
	 {
	 	for(int j=1;j<=5-i;j++)
			if(a[j]>a[j+1]) swap(a[j],a[j+1]);
		printf("%d:",i);
		for(k=1;k<=5;k++)
		  printf("%d ",a[k]);
		printf("\n");
	 }
	for(i=1;i<=5;i++)
		printf("%d ",a[i]);
	return 0;
}
