#include<bits/stdc++.h>
using namespace std;
struct node{
	long long lef,rig;
}in[1001],boss;
int n;
bool cmp(node a,node b)
{
	return (a.rig<b.rig);
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	cin>>in[0].lef>>in[0].rig;
	for(int i=1;i<=n;i++)
		cin>>in[i].lef>>in[i].rig;
	sort(in+1,in+n+1,cmp);
	for(int i=0;i<=n;i++)
	 cout<<in[i].lef<<" "<<in[i].rig<<endl;
	int ans=-1000000;
	for(int i=1;i<=n;i++)
	{
		int tmp=1;
		for(int j=0;j<i;j++)
		{
			tmp*=in[j].lef;
		}
		tmp/=in[i].rig;
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
}