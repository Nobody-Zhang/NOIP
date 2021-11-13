#include<bits/stdc++.h>
using namespace std;
int a[1000005]={};
int main()
{
	int o,i;
	cin>>o; 
	for(i=2;i<=o;i++)
		if(a[i]==0)
		{
			printf("%d ",i);
			for(int j=2*i;j<=o;j+=i)
			a[j]=1;
		}
	return 0;
}
