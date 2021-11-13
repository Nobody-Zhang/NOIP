#include<bits/stdc++.h>
using namespace std;
int n,m;
char t[100005],w[100005];
int f[10][70000];
int main(){
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s%s",t+1,w+1);
	int now,pre,now2=0; 
	for(int i=1;i<=n;i++)
	{
		now=i&1,pre=now^1;
		for(int j=1;j<=m ;j++){
			if(t[i]==w[j])f[now][j]=f[pre][j-1]+1;
			else f[now][j]=max(f[pre][j],f[now][j-1]);
		}	
	}
	cout<<f[n&1][m]<<endl;
	return 0;
}
/*
5 6
abdac
adabac
*/
