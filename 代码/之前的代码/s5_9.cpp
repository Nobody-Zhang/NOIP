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
	printf("����%lf ����%lf ƽ������%lf",n,j,m);
	return 0;
}
