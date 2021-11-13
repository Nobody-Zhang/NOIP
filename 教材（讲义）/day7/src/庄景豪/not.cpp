#include<bits/stdc++.h>
using namespace std;
bool used[13];
int a[12][10001],w[12][10001],ans,n,m,tot[12],sh[13];
void RC(int lun)
{
	if(lun==n+1)return;
	int f=1;
	if(lun&1)f=-1;
	for(int i=1;i<=tot[lun];i++){
		ans+=f*(m/a[lun][i]);
	}
	RC(lun+1);
}
int main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	scanf("%d%d",&n,&m);
	ans=m;
	for(int i=1;i<=n;i++){
		scanf("%d",&sh[i]);
	}
	for(int i=1;i<=n;i++){
		bool fl=false;
		for(int j=1;j<=tot[1];j++)
			if(sh[i]%sh[j]==0){
				fl=true;break;
			}
		if(!fl){
			a[1][++tot[1]]=sh[i];
			w[1][tot[1]]=tot[1];
		}
	}
	for(int i=2;i<=tot[1];i++){
		for(int l=1;l<=tot[i-1];l++)
		for(int k=w[i-1][l]+1;k<=tot[1];k++){
			w[i][++tot[i]]=k;
			a[i][tot[i]]=a[1][k]*a[i-1][l];
			if(a[1][k]*1ll*a[i-1][1]>m)tot[i]--;
		}
	}
	RC(1);
	printf("%d",ans);
}
