#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define maxn 100002
using namespace std;

inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9')s=getchar();
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+s-'0';s=getchar();}
}

int T,n,m,a,b;
int jmp[maxn];
double dp[maxn];

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n+6;++i)dp[i]=0,jmp[i]=0;
	for(int i=1;i<=m;++i){
		int a,b;scanf("%d%d",&a,&b);jmp[a]=b;
	}
	for(int i=n-1;i>=0;--i){
		dp[i]=0;if(!jmp[i])for(int j=1;j<=6;++j)dp[i]+=(dp[i+j]+1)/6;
		else dp[i]=dp[jmp[i]];
	}
	printf("%.2f\n",dp[0]);
}

int main(){
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	read(T);
	while(T--){
		solve();
	}
}
