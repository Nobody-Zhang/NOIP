#include<bits/stdc++.h>
using namespace std;
long long i[10005];
int main()
{
	freopen("acme.in","r",stdin);
	freopen("acme.out","w",stdout);
	int m;
	cin>>m;
	i[0]=1,i[1]=1;
	int j;
	for(j=2;j<=100005;j++)
	{
		i[j]=i[j-1]+i[j-2];
		if(i[j-1]>m) break;
	} 
	cout<<"m="<<i[j-3]<<endl;
	cout<<"n="<<i[j-2];
	return 0;
}
