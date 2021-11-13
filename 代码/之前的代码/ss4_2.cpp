#include<bits/stdc++.h>
using namespace std;
int main(){
	char a,b,c,d;
	scanf("%c%c%c",&a,&b,&c);
	if(a>b){
		d=a;
		a=b;
		b=d;
	}
	if(a>c){
		d=a;
		a=c;
		c=d;
	}
	if(b>c){
		d=b;
		b=c;
		c=d;
	}
	printf("%c%c%c",a,b,c);
	return 0;
}
