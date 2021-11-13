#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define maxn 2000002
using namespace std;

inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9')s=getchar();
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+s-'0';s=getchar();}
}
inline void print(long long x){
	if(x>9)print(x/10);
	putchar(x%10+48);
}

int n,k,id;
int num[maxn],sum[2][maxn];
bool tof[maxn];
int main(){
	long long ans=0,x;
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	read(n),read(k);
	for(int i=1;i<=n;i++)read(num[i]),sum[0][i]=i,sum[1][i]=num[i];
	sort(num+1,num+n+1);
	for(int i=n;i>=1;i--){
		for(int j=n;j>=1;j--){
			if(num[i]==sum[1][j]){x=sum[0][j];tof[x]=true;break;}
		}
		bool flag=false;
		for(int j=n;j>=1;j--){
			if(tof[j])id++;
			else{id=0;}
			if(id>k){flag=true;break;}
		}
		if(flag){
			tof[x]=false;id=0;
			continue;
		}
		else{
			ans+=num[i];id=0;
		}
	}
	print(ans);
}
