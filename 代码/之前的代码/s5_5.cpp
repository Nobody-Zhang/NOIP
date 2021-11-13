#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c=1;
	double pai=0;
	for(a=1;1.0/a>=pow(10,-6);a=a+2)
	{
		pai+=c*1.0/a;
		c=-c;
	}
	printf("%0.10lf",4*pai);
}
