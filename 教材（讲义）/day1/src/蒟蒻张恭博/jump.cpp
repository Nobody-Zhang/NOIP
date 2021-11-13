#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define maxx 500001
long long f[maxx],v[maxx],s[maxx],n,d,k,lef,rig,ans;
int check(int m)
{
	for(int i=1;i<=n;i++) s[i]=-1e18;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(f[j]-f[i]>d+m) break;
			if(f[j]-f[i]<max((long long)1,d-m)) continue;
			s[j]=max(s[j],s[i]+v[j]);
			if(s[j]>k) return 1;
		}
	return 0;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i]>>v[i];
		rig=max(rig,f[i]-f[i-1]);
		if(v[i]>0) sum+=v[i];
	}
	if(sum<k){
		cout<<"-1"<<endl;
		return 0;
	}
	rig+=d;
	while(rig>=lef)
	{
		int mid=(lef+rig)/2;
		check(mid)?ans=mid,rig=mid-1:lef=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}
