#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[200]={0,1,1},i;
	printf("1,1");
	for(i=3;i<=20;i++)
	
	{
		a[i]=a[i-2]+a[i-1];
		printf(",%d",a[i]);
	}
}
