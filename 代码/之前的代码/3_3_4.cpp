#include<bits/stdc++.h>
long long a[101],b[101],i,j,x,y,z;
int main()
{
	freopen("3_4.in","r",stdin);
	freopen("3_4.out","w",stdout);
	std::cin>>x>>y>>z;
	for(i=1;i<=x;i++)
	{
		a[i]=1;
		b[i]=0;
	}
	for(int i=x+1;i<=z+1;i++)
	{
		b[i]=y*a[i-x];
		a[i]=a[i-1]+b[i-2];
	}
	std::cout<<a[z+1]<<std::endl;
	return 0;
}
