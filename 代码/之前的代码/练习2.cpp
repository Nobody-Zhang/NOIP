#include<bits/stdc++.h>
using namespace std;
int main(){
	double a,b;
	scanf("%lf",&a);
	if(a>=20)
		b=20*(a-20);
	else
		b=0;
	printf("%0.1lf",b); 
	return 0; 
}
