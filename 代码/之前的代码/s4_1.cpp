#include<bits/stdc++.h>
using namespace std;
int main(){
	double x,y;
	scanf("%lf",&x);
	if(x>20)
		y=(x-20)*20;
	else
		y=0;
	printf("y=%0.1lf",y);
	return 0;
}
