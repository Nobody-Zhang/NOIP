#include<bits/stdc++.h>
using namespace std;

const int maxn=505;
int n,m;
int ti[maxn];
int f[maxn][maxn];//���i���˵�j���ӵ�ʱ������ܺ�ʱ 

int dfs(int s,int st){
	if(s>n) return 0;
	if(st<ti[s]) return dfs(s,ti[s]);//��ǰʱ��û����,ֱ��ȥ���¸��� 
	if(f[s][st-ti[s]])  return f[s][st-ti[s]];//���仯���� 
	int sum=0,i=s;
	
	while(i<=n&&ti[i]<=st) sum+=ti[i++];
	int ans=st*(i-s)-sum+dfs(i,st+m);//�˵ȳ�,�˵ȵ���೵��,st*(i-s)-sum��Ϊ�ȴ�ʱ��
	
	while(i<=n){
		sum+=ti[i];
		ans=min(ti[i]*(i-s+1)-sum+dfs(i+1,ti[i]+m),ans);//������,���ȵ���i����һ���� 
		//ti[i]*(i-s+1)-sumΪ�ȴ�ʱ�� 
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
