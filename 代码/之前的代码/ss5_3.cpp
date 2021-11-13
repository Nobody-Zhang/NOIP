#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d,e,f;
	for(a=1;a<=999;a++)
	{
		b=a%3;
		if((a/100==5||a%100/10==5||a%10==5)&&b==0)
		printf("%d\n",a);
	}
	return 0;
}
