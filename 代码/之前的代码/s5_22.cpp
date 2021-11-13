#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,i,s;
	scanf("%d%d",m,n);
	for(i=m;i<=n;i++)
	{
		if(i/1000==2) s++;
		if(i%1000/100==2) s++;
		if(i%100/10==2) s++;
		if(i%10==2) s++;
	}
	printf("%d",s);
	return 0;
}
