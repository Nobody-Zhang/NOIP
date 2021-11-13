#include<bits/stdc++.h>
using namespace std;
int main(){
	int i=0;
	double s=0;
	do
	{
		i++;
		s+=1.0/i;
	}
	while(s<=10);
	printf("%d",i);
	return 0;
}
