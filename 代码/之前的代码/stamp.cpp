#include<bits/stdc++.h>
using namespace std;
int m,n,f[2000000],as,k;//f是能凑出其的邮票数目 
int main()
{
	//freopen("stamp.in","r",stdin);
	//freopen("stamp.out","w",stdout);
	cin>>n>>m;//m是可用总数 n是面值数量 
	for(int i=1;i<=2000000;i++) 
	f[i]=666666;
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int h=k;h<=2000000;h++)
		if(f[h-k]+1<=m) 
		f[h]=min(f[h],f[h-k]+1);
	}
	for(int i=1;i<=2000000;i++)
	if(f[i]==666666)
	{
		as=i-1;
		break;
	}
	cout<<as;
	return 0;
}
