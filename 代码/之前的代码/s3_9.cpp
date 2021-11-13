#include<bits/stdc++.h>
int main()
{
	int a,b,c,d;
	scanf("%d",&a);
	b=a/100;
	c=(a-100*b)/10;
	d=a-100*b-10*c;
	printf("他的百位是%d 十位%d 个位%d",b,c,d);
	return 0;
}
