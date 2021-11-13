#include <stdio.h>
void out2()
{
	printf("Jan: 31\nFeb: 28\nMar: 31\nApr: 30\nMay: 31\nJun: 30\nJul: 31\nAug: 31\nSep: 30\nOct: 31\nNov: 30\nDec: 31\n");
}
void out1()
{
	printf("Jan: 31\nFeb: 29\nMar: 31\nApr: 30\nMay: 31\nJun: 30\nJul: 31\nAug: 31\nSep: 30\nOct: 31\nNov: 30\nDec: 31\n");
}
int main() {
	/**********Begin**********/
	int n;
	scanf("%d",&n);
	if(n%100==0){
		if(n%400==0) out1();
		else out2();
	}
	if(n%4==0){
		out1();
	}
	out2();
	/**********End**********/
	return 0;
}