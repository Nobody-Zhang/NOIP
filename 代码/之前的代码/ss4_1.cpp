#include<bits/stdc++.h>
using namespace std;
int main (){
	int a,b;
	scanf("%d",&a);
	if(a<=20){
		b=2*a;
	}
	if(a>20)
		b=2*20+3*(a-20);
	printf("%d",b);
}
