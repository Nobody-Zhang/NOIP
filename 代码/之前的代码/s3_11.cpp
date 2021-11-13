#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a,b,c,p,s;
	scanf("%lf%lf%lf",&a,&b,&c);
	p=(a+b+c)/2;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	cout<<"这个三角形的面积是"<<s<<endl; 
}
