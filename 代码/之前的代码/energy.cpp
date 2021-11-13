#include<bits/stdc++.h>
using namespace std;
int f[310][310];
int a[310];
int n;
int dp(int l,int r){
    int &ans=f[l][r];
    if(ans)return ans;
    if(l==r-1)return ans=a[l]*a[r]*a[r+1];
    for(int i=l;i<r;i++)
        ans=max(ans,a[l]*a[i+1]*a[r+1]+dp(l,i)+dp(i+1,r));
    return ans;
}
int main(){
    //freopen("energy.in","r",stdin);
    //freopen("energy.out","w",stdout);
	cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],a[n+i]=a[i];
    a[2*n+1]=a[1];
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,dp(i,i+n-1));
    cout<<ans;
    return 0;
}
