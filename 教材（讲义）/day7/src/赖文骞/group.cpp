#pragma GCC optimize (2)
#include <deque>
#include <cstdio>
using namespace std;
#define input(x) freopen(x,"r",stdin)
#define output(x) freopen(x,"w",stdout)

deque <int> que;
long long a[2000005],prev[2000005],dp[2000005];

inline long long getnum(void)
{
	long long ans=0;
	int minus=1;
	char c=getchar();

	if(c=='-') minus=-1;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		ans=ans*10+c-'0';
		c=getchar();
	}
	ans*=minus;

	return ans;
}

inline void putnum(long long x)
{
	if(!x)
	{
		putchar('0');
		return;
	}
	if(x<0)
	{
		putchar('-');
		x*=-1;
	}

	int num=0;
	char c[20];

	while(x)
	{
		c[++num]=x%10+'0';
		x/=10;
	}

	while(num) putchar(c[num--]);
	return;
}

int main()
{
	input("group.in");
	output("group.out");
	int n=getnum(),k=getnum();
	
	for(int i=1;i<=n;i++)
	{
		long long val;
		
		a[i]=getnum();
		
		prev[i]=prev[i-1]+a[i];
		val=dp[i-1]-prev[i];
		while(!que.empty()&&que.front()<i-k) que.pop_front();
		while(!que.empty()&&val>=dp[que.back()-1]-prev[que.back()]) que.pop_back();
		que.push_back(i);
		if(i>k) dp[i]=dp[que.front()-1]-prev[que.front()]+prev[i];
		else dp[i]=prev[i];
	}
	
	putnum(dp[n]);
	return 0;
}
