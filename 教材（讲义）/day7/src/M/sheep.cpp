#include<bits/stdc++.h>
using namespace std;
const int MaxN=1e5+5;

double f[MaxN],hzh[MaxN];
int jump[MaxN];
int T,n,m,x,y;

int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	scanf ("%d",&T);
	for(register int i=1;i<=T;i++){
		memset(f,0,sizeof(f));
		memset(jump,0,sizeof(jump));
		scanf("%d%d",&n,&m);

		for(register int j=1;j<=m;j++){
			scanf ("%d%d",&x,&y);
			jump[x]=y;
		}

		for(register int i=n-1;i>=0;i--){
			if(!jump[i]){
				for(register int j=1;j<=6;j++){
					f[i]+=(f[i+j]/6.0);
				}
				f[i]++;
			}else{
				f[i]=f[jump[i]];
			}
		}
		printf ("%0.2lf\n",f[0]);
	}
}

/*#include<bits/stdc++.h>
using namespace std;
const int MaxN=1e5+5;

double dp[MaxN];
int n,lim,m,nex[MaxN];

void pass(int loc)
{
	int now;
	while(nex[now]!=now){
		now=nex[now];
		dp[loc]+=dp[loc];
	}
}

void work(int loc)
{
	for(int i=loc+1;i<=loc+6&&i<=lim;i++){
		dp[i]+=(1.0/6);
		if(nex[i]!=i) pass(i);
	}
}

int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		lim=n+5;
		for(int i=1;i<=lim;i++){
			dp[i]=0;nex[i]=i;
		}
		int t1,t2;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&t1,&t2);
			nex[t1]=min(n,t2);
		}
		if(m){
			for(int i=n;i>=0;i--){
				if(nex[i]!=i) nex[i]=nex[nex[i]];
			}
		}
		for(int i=0;i<n;i++){
			work(i);
		}
		double ans=0;
		for(int i=n;i<=n+5;i++)
			ans+=dp[i];
		printf("%lf\n",ans);
	}
	return 0;
}*/