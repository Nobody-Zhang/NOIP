#include<bits/stdc++.h>
using namespace std;
#define maxn 100001
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
template <typename T> inline void redi(T&t)
{
	register int c=getchar();t=0;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) t=t*10+c-'0',c=getchar();
	return;
}
template <typename T,typename... Args> inline void redi(T& t, Args&... args){
	redi(t);
	redi(args...);
}
long long dp[maxn],in[maxn],qzh[maxn];
struct s{
	long long data;
	int pos;
}que[maxn];
int front,tail;
int n,k;
void f(int now)
{
	long long tmp=dp[now-1]-qzh[now];
	while(front!=tail&&tmp>que[tail].data){
		tail--;
	}
	que[++tail].data=tmp;
	que[tail].pos=now;
	return;
}
int main()
{
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	redi(n,k);
	for(int i=1;i<=n;i++)
		redi(in[i]),qzh[i]=qzh[i-1]+in[i];
	for(int i=1;i<=k;i++)
	{
		dp[i]=qzh[i];
		f(i+1);
		/*que[tail++].data=dp[k-1]-qzh[k];
		que[tail].pos=k;*/
	}
	for(int i=k+1;i<=n;i++)
	{
		while(tail!=front&&que[front].pos+k<i){
			front++;
		}
		dp[i]=que[front].data+qzh[i];
		f(i+1);
	}
	cout<<dp[n]<<endl;
	return 0;
}
