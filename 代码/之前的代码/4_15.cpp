#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d,e;
	scanf("%d",&a);
	b=a/100;
	c=a%100/10;
	d=a%10;
	if(a>=1000)
		printf("����������˳�����������");
	else if(a>=100)
		printf("%d����λ��\nÿһλ���ֱַ�Ϊ��%d  %d  %d\n�������Ϊ%d%d%d",a,b,c,d,d,c,b);
	else if(a>=10)
		printf("%d����λ��\nÿһλ���ֱַ�Ϊ��%d  %d\n�������Ϊ%d%d",a,c,d,d,c);
	else if(a>=0)
		printf("%d��һλ��\nÿһλ���ֱַ�Ϊ��%d\n�������Ϊ%d",a,a,a);
	return 0;
	
}
