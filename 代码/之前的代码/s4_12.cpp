#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	scanf("%d",&a);
	b=a%4;
	c=a%100;
	d=a%400;
	if((c!=0||d==0)&&b==0)
		printf("��������");
	else
		printf("����������"); 
	return 0;
}
