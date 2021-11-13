#include<bits/stdc++.h>
using namespace std;
int main(){
	double a,b;
	scanf("%lf%lf",&a,&b);
	if(a>=b)
		printf("%lf %lf",a,b); 
	else
		printf("%lf,%lf",b,a); 
	return 0; 
}
