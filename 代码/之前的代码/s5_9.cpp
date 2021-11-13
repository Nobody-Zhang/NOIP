#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,i;
	double m,n,b,j=1;
	cin>>a;
	for(i=1;i<=a;i++)
	{
		cin>>b;
		n+=b;
		j=j*b;
	}
	m=1.0*n/a;
	printf("和是%lf 积是%lf 平均数是%lf",n,j,m);
	return 0;
}
