#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,n;
	//double n;
	for(n=100;n<1000;n++)
	{
		a=n/100;
		b=n%100/10;
		c=n%10;
		//for(;n==a*a*a+b*b*b+c*c*c;n=n+0.5)
		//	cout<<n<<endl;
		if(n==a*a*a+b*b*b+c*c*c)
			{
				cout<<n<<endl;
			}
	}
	return 0;
}
