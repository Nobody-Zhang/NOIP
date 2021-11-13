#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15];
int aa[15];

long long pre[15][15];
int ans;

void dfs(int last,int s,long long base){
	if(s>aa[0])  return ;
	for(int i=last+1;i<=aa[0];i++){
		if(base*i>m) return ;
		pre[s][++pre[s][0]]=base*aa[i];
		dfs(i,s+1,base*aa[i]);
	}
}

int main(){
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		bool bj=false;
		for(int j=1;j<=aa[0];j++)
		 if(a[i]%aa[j]==0){bj=true;break;}
		if(!bj) aa[++aa[0]]=a[i];
	}
	  
	//for(int i=1;i<=aa[0];i++) printf("%d ",aa[i]);
	dfs(0,1,1);
	int bj=1;
	ans=m;
	for(int i=1;i<=aa[0];i++){
		bj*=-1;
		for(int j=1;j<=pre[i][0];j++)
		  ans=ans+(m/pre[i][j])*bj;
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=pre[i][0];j++)
		  printf("%d ",pre[i][j]);
		printf("\n");
	}*/
	  
	printf("%d",ans);
}
/*
4 100
5 6 48 40
*/
