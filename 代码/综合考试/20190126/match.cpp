//最长公共子序列(上升子序列转换)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int m,s1[100001],s2[100001];
int in[100001],c[100001],f[100001],ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	 {
	     scanf("%d",&s1[i]);
	     c[s1[i]]=i;
	 }
	for(int i=1;i<=m;i++)
	 {
	     scanf("%d",&s2[i]);
	     in[i]=c[s2[i]];
	 }
    int len=1;
    memset(f,10,sizeof(f));
    for(int i=1;i<=m;i++)
    {
        int *p=lower_bound(f+1,f+1+m,in[i]);
        (*p)=in[i];
    }
    for(int i=1;i<=m;i++)
    if(f[i]==f[0]){
        ans=i-1;
        break;
    }
    cout<<ans<<endl;
	return 0;
}
