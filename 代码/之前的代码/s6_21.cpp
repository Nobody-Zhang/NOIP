#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n,m,b,s,k;
	k=0;
	scanf("%d%d",&n,&m);
	for(b=0;b<n;b++)
	{
		s=0;
		while(s<m)
		{
			k++;
			if(k>n) k=1;
			if(a[k]==0) s++;
		}
		a[k]=1;
	}
	printf("%d",k);
	return 0;
}
