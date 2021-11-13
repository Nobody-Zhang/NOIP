#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;
	char b;
	scanf("%d",&a);
	if(a>=90)
		b='A';
	if(a<90&&a>=80)
		b='B';
	if(a<80&&a>=70)
		b='C';
	if(a<70&&a>=60)
		b='D';
	else if(a<60)
	b='E';
	printf("%c",b);
	return 0;
}
