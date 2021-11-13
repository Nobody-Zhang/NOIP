//#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
int main()
{
	cin>>n>>m;
	int x1,y1,x2,y2,x3,y3;
	for(x1=0;x1<=n;x1++)
	{
		for(y1=0;y1<=m;y1++)
		{
			ans+=min(m-y1,n-x1);
			/*for(int t=1;x1+t<=n&&y1+t<=m;t++)
			 ans++;*/
		}
	}
	cout<<ans<<" ";
	long long tot=ans;
	ans=0;
	for(x1=0;x1<=n;x1++)
	{
		for(y1=0;y1<=m;y1++)
		{
			ans+=(n-x1)*(m-y1);
			/*for(x2=x1+1;x2<=n;x2++)
				for(y2=y1+1;y2<=m;y2++)
				 ans++;*/
		}
	}
	cout<<ans-tot<<endl;
	return 0;
}