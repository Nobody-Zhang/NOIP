#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int s=0,n,a,t=1,i;
	cin>>n>>a;
	for(i=1;i<=n;i++)
	{	
	
		s=s+a*t;
	 	t=10*t+1;	
	}
	printf("%d",s);
	return 0;
}
