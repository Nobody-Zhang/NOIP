#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int a;
	scanf("%d",&a);
	if(a>=1&&a<=7)
	{
		
		if(a==1) printf("今天是星期一");
		if(a==2) printf("今天是星期二");
		if(a==3) printf("今天是星期三");
		if(a==4) printf("今天是星期四");
		if(a==5) printf("今天是星期五");
		if(a==6) printf("今天是星期六");
		if(a==7) printf("今天是星期七");
	}
	else
	printf("输入错误");
	return 0;
}
