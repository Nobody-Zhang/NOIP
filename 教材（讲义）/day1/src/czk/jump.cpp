#include<bits/stdc++.h>
#define ll long long
using namespace std;
int  ans,maxx=0x7f7f7f,n,d,k,N=500005;
ll sum=0;
ll x[N],q[N],a[N],dp[500005];
bool check(int g){
	memset(dp,-0x7f7f7f,sizeof(dp));
	int head=1,tail=0,mi=d-g>0?d-g:1,mx=d+g,df=0x7f7f7f,fir=-1;
	q[tail++]=0;f[0]=0;
	for(int i=1;i<=n;i++){
		if(x[i]-x[i-1]<mi)continue;
		if(x[i]-x[i-1]>mx)break;
		if(fir==-1){
			fir=i;
		}
		while(x[i]-x[fir]>=mi&&fir<i){
			while(dp[fir]>dp[q[tail]]&&head<=tail){
				tail--;
			}
			q[++tail]=first++;
		}
		while(head<=tail&&x[q[head]]+mx<x[i])head++;
		if(head>tail)f[i]=-0x7f7f7f;
		else f[i]=f[q[head]]+a[i];
		if(df>f[i])df=f[i];
		
	}
	return (df>=k);
}
int main(){
	freopen ("jump.in","r",stdin);
	freopen ("jump.out","w",stdout);
	cin>>n>>d>>k;
	x[0]=0;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>a[i];
		maxx=max(maxx,x[i]);
		if(a[i]>0)sum+=a[i];
	}
	if(sum<k){
		cout<<"-1\n";
		return 0;
	}
	int d=0,mid,q=maxx;
	while(d<q){
		mid=(d+q)/2;
		if(check(mid)){
			ans=mid;q=mid+1;
		}
		else d=mid-1;
	}
	cout<<ans<<endl;
}
/*
7 4 10
2 6
5 -3
10 3
11 -3
13 1
17 6
20 2

2*/
