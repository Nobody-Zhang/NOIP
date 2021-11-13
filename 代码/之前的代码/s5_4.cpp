#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i,t=1;
	double s=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		s+=1.0/i*t;
		t=-t;
	}
	printf("%0.4lf",s);
	return 0;
}
