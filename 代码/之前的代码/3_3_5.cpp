#include<bits/stdc++.h>
using namespace std;
int f[1001][2],n,i,x;
int main()
{
	freopen("3_5.in","r",stdin);
	freopen("3_5.out","w",stdout);
	cin>>n;
	f[1][0]=9;
	f[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		x=f[1][0];
		if(i==n) x--;
		f[i][0]=(f[i-1][0]*x+f[i-1][1])%12345;
		f[i][1]=(f[i-1][0]+f[i-1][1]*x)%12345;
	}
	cout<<f[n][0];
	return 0;
}
