#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;
	char b;
	scanf("%d",&a);
	if(a>=90)
		b='A';
	else if(a>=80)
		b='B';
	else if(a>=70)
		b='C';
	else if(a>=60)
		b='D';
	else if(a<60)
	b='E';
	printf("%c",b);
	return 0;
}
