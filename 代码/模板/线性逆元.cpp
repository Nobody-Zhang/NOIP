#include<bits/stdc++.h>
using namespace std;
#define maxn 3000010
unsigned long long phi[maxn];
int main()
{
	int n,p;
	scanf("%d%d",&n,&p);
	phi[1]=1;
	for(int i=2;i<=n;i++)
		phi[i]=(p-p/i)*phi[p%i]%p;
	for(int i=1;i<=n;i++)
		printf("%lld\n",phi[i]);
	return 0;
}
