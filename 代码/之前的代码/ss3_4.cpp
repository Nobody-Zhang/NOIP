#include<bits/stdc++.h>
int main()
{
	int a,b,c,d,e;
	scanf("%d",&a);
	b=a/100;
	c=(a-b*100)/10;
	d=a%10;
	e=d*100+c*10+b;
	printf("%d",e);
}
