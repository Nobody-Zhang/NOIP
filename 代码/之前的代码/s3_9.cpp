#include<bits/stdc++.h>
int main()
{
	int a,b,c,d;
	scanf("%d",&a);
	b=a/100;
	c=(a-100*b)/10;
	d=a-100*b-10*c;
	printf("���İ�λ��%d ʮλ%d ��λ%d",b,c,d);
	return 0;
}
