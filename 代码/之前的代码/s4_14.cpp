#include<bits/stdc++.h>
using namespace std;
int main(){
	double a,b,c,f,e,x1,x2;
	printf("����������a,b,c��ֵ\n"); 
	scanf("%lf%lf%lf",&a,&b,&c);
	if(a==0)
		printf("������һԪ���η���\n");
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
		printf("�������û��ʵ��\n"); 
	printf("�����������");
	getchar();
	getchar();
	
	
	return 0;
}
