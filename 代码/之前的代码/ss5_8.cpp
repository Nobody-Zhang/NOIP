#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,i;
	cin>>a;
	for(b=1;b<=a;b=b+2)
		if(a*(b+a-1)==a*a*a) break;
	for(i=1;i<a;i++)
	{
		b=b+2;
		printf("%d+",b);
	}
		
	printf("%d=%d",b+2,a*a*a);
	return 0;
}
