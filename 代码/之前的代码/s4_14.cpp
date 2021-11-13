#include<bits/stdc++.h>
using namespace std;
int main(){
	double a,b,c,f,e,x1,x2;
	printf("请依次输入a,b,c的值\n"); 
	scanf("%lf%lf%lf",&a,&b,&c);
	if(a==0)
		printf("他不是一元二次方程\n");
	if(a!=0) 
		e=b*b-4*a*c;
		if(e>=0)
		{
			f=sqrt(e);
			x1=(-b+f)/a/2;
			x2=(-b-f)/a/2;
			printf("x1=%0.2lf   x2=%0.2lf\n",x1,x2);
		}
		else
		printf("这个方程没有实根\n"); 
	printf("按任意键继续");
	getchar();
	getchar();
	
	
	return 0;
}
