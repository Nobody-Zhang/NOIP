#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d,e;
	scanf("%d",&a);
	b=a/100;
	c=a%100/10;
	d=a%10;
	if(a>=1000)
		printf("输入错误，请退出后重新输入");
	else if(a>=100)
		printf("%d是三位数\n每一位数字分别为：%d  %d  %d\n逆序输出为%d%d%d",a,b,c,d,d,c,b);
	else if(a>=10)
		printf("%d是两位数\n每一位数字分别为：%d  %d\n逆序输出为%d%d",a,c,d,d,c);
	else if(a>=0)
		printf("%d是一位数\n每一位数字分别为：%d\n逆序输出为%d",a,a,a);
	return 0;
	
}
