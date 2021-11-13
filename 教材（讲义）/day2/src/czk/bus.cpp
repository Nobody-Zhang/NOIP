#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,t[1000],maxt=0,cnt[6654321]={0},sum[6654321]={0},f[6654321]={0};
int m;
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t[i];
		cnt[t[i]]++;sum[t[i]]+=t[i];maxt=max(maxt,t[i]);
	} 
	for(int i=0;i<maxt+m;i++){
		cnt[i]+=cnt[i-1];
		sum[i]+=sum[i-1];
	}
	f[0]=0;
	for(int i=1;i<=maxt+m;i++){
		if(i>=m&&cnt[i]==cnt[i-m]){
			f[i]=f[i-m];continue;
		}
		f[i]=cnt[i]*i-sum[i];
		for(int j=max(i-m-m+1,0);j<=i-m;j++){
			f[i]=min(f[i],f[j]+(cnt[i]-cnt[j])*i-sum[i]+sum[j]);
		}
	}
	ll ans=1e9;
	for(int i=maxt;i<maxt+m;i++){
		ans=min(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 1 
3 4 4 3 5

0*/
