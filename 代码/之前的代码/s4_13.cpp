#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d,e,f;
	scanf("%d%d",&a,&e);
	b=a%4;
	c=a%100;
	d=a%400;
	if(e==1||e==3||e==5||e==7||e==8||e==10||e==12)
		f=31;
	if(e==4||e==6||e==9||e==11)
		f=30;
	if(e==2)
	if((c!=0||d==0)&&b==0)
		f=29;
	else
		f=28;
	printf("%d",f);
	return 0;
}
