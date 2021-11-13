#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,q,w=0;
	scanf("%d",&n);
	for(i=2;i<n;i++)
	{
		q=n%i;
		if(q==0)
			w++;
	}
	if(w==0)
		printf("YES!");
	if(w!=0)
		printf("NO!");
	return 0; 
}
