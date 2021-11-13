#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d,i,n,min;
	scanf("%d%d",&a,&b);
	if (a<b) min=a;
	else min=b;
	for (i=min;i>=1;i--)
	  if (a%i==0&&b%i==0) break;
	c=i;
	for (i=min;i>=min;i++)
      if (i%a==0&&i%b==0) break;
	d=i;
	printf("最大公约数是%d最小公倍数是%d",c,d);
	return 0;
}
