#include<algorithm>
#include<queue>
#include<cstdio>
#include<memory.h>
using namespace std;

int n,k,a[2000001];
long long f[2000001],qzh[2000001];
long long op,maxx;
deque < pair<long long,int> > que;

int main()
{
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	scanf ("%d%d",&n,&k);
	for(register int i=1;i<=n;i++)
	{
		scanf ("%d",&a[i]);
		qzh[i]=qzh[i-1]+a[i];
	}
	f[1]=a[1];
	que.push_back(make_pair(0,0));
	for(register int i=1;i<=n;i++)
	{
		for (;!que.empty()&&que.back().first<f[i-1]-qzh[i];) 
			que.pop_back();
		op=f[i-1]-qzh[i];
		que.push_back (make_pair(op,i));
		for (;!que.empty()&&que.front().second<i-k;) 
			que.pop_front();
		maxx=que.front().first;
		if(i>1) 
			f[i]=maxx+qzh[i];
	}
	printf("%I64d\n",f[n]);
	return 0;
}
