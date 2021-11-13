#include<bits/stdc++.h>
using namespace std;
int main(){
	double a,b,c;
	char f;
	scanf("%lf%c%lf",&a,&f,&b);
	if(f=='+') c=a+b;
	if(f=='-') c=a-b;
	if(f=='*') c=a*b;
	if(f=='/') c=a/b;
	printf("%0.2lf",c);
	return 0;
}
