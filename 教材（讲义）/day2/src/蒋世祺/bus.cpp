#include<bits/stdc++.h>
using namespace std;

const int maxn=505;
int n,m;
int ti[maxn];
int f[maxn][maxn];//存第i个人等j分钟的时候最短总耗时 

int dfs(int s,int st){
	if(s>n) return 0;
	if(st<ti[s]) return dfs(s,ti[s]);//当前时间没有人,直接去接下个人 
	if(f[s][st-ti[s]])  return f[s][st-ti[s]];//记忆化搜索 
	int sum=0,i=s;
	
	while(i<=n&&ti[i]<=st) sum+=ti[i++];
	int ans=st*(i-s)-sum+dfs(i,st+m);//人等车,人等到这班车走,st*(i-s)-sum即为等待时间
	
	while(i<=n){
		sum+=ti[i];
		ans=min(ti[i]*(i-s+1)-sum+dfs(i+1,ti[i]+m),ans);//车等人,车等到第i个人一起走 
		//ti[i]*(i-s+1)-sum为等待时间 
		i++;
	}
	return f[s][st-ti[s]]=ans;
}

int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%d",&ti[i]);
	if(m==1){printf("0");return 0;}
	sort(ti+1,ti+n+1);
	printf("%d",dfs(1,0));
}
