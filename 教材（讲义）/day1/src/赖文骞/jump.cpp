#include <deque>
#include <cstdio>
#include <climits>
#include <algorithm>
#define input(x) freopen(x,"r",stdin)
#define output(x) freopen(x,"w",stdout)

struct data
{
	int dis,val;
}block[500005];
std::deque <int> que;
int n,d,k;
long long f[500005];

long long dp(int L,int R)
{
	int p=0;
	long long ret=LLONG_MIN;
	
	f[0]=0;
	for(int i=1;i<=n;i++) f[i]=LLONG_MIN;
	que.clear();
	
	for(int i=1;i<=n;i++)
	{
		while(block[i].dis-block[p].dis>=L&&p<i)
		{
			if(f[p]!=LLONG_MIN)
			{
				while(!que.empty()&&f[que.back()]<=f[p]) que.pop_back();
				que.push_back(p);
			}
			p++;
		}
		while(!que.empty()&&block[i].dis-block[que.front()].dis>R) que.pop_front();
		if(!que.empty()) f[i]=f[que.front()]+block[i].val;
	}
	for(int i=1;i<=n;i++) ret=std::max(ret,f[i]);
	
	return ret;
}

int main()
{
	input("jump.in");
	output("jump.out");
	int L=0,R;
	long long ans=-1LL,sum=0LL;
	
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&block[i].dis,&block[i].val);
		
		if(block[i].val>0) sum+=block[i].val;
	}
	
	if(sum<k)
	{
		printf("-1");
		return 0;
	}
	R=std::max(block[n].dis,d);
	while(L<=R)
	{
		int M=(L+R)>>1;
		long long tmp=dp(std::max(1,d-M),d+M);
		if(tmp<k) L=M+1;
		else
		{
			ans=M;
			R=M-1;
		}
	}
	
	printf("%I64d",ans);
	return 0;
}
