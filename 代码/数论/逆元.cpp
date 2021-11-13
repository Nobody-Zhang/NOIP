#include<bits/stdc++.h>
using namespace std;
#define N 620000
int inv[N];
int main()
{
	int m,p;
	cin>>m>>p;
	inv[1]=1;
	for(int i=2;i<=m;i++)
	 inv[i]=(-p/i*inv[p%i]+p)%p;
	cout<<inv[m]<<endl;
	return 0;
}
