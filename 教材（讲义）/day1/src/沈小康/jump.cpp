#include<bits/stdc++.h>
#define N 500001 
#define INF 100000000000 
using namespace std;
typedef long long ll;
int n;  ll d,k,ans;

int now;//当前进行到的位置 
int q[N*2];//队列中的元素位置
ll loc[N],point[N];
ll f[N];//表示到当前位置可以达到的最高分 

template <class T>
void read(T &x)
{
	char c;int sign=1;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1; x=c-48;
	while((c=getchar())>='0'&&c<='9') x=(x<<1)+(x<<3)+c-48; x*=sign;
}

bool check(ll g)
{
	ll maxx=0;
	ll l=max(1LL,d-g),r=d+g;//两端点 
	f[0]=0;//起点分数为0 
	now=0;
	
	int head=1,tail=0;
	
	for(int i=1;i<=n;++i)
	{
		f[i]=-INF;
		ll L=loc[i]-r,R=loc[i]-l;//维护单调递减的序列
		while(now<=n&&loc[now]<=R)//当前处理到的位置在右端点左边
		{
			while(head<=tail&&f[q[tail]]<f[now]) tail--;
			q[++tail]=now++;
		}
		while(head<=tail&&loc[q[head]]<L) head++;//出队 
		
		if(head>tail) continue;//空队列 
		
		f[i]=f[q[head]]+point[i];
		maxx=max(maxx,f[i]);
	}
	return maxx>=k;
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	read(n);read(d);read(k);
	ans=INF;
	ll num=0;
	for(int i=1;i<=n;++i)
	{
		read(loc[i]);read(point[i]);
		if(point[i]>0) num+=point[i];
	}
	if(num<k)//所有正数加起来仍然比目标小 
	{
		cout<<-1<<endl;
		return 0;
	}
	ll l=0,r=1000000001;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid)) r=mid-1,ans=min(ans,mid);
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}
