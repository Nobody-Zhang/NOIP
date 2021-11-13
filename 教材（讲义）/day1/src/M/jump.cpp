#include<cstdio>
#include<algorithm>
using namespace std;

struct point
{
	int pos;
	long long ans;
};
point a[600005],q[600005];
long long ans[600005];
int n,d,k,left=0,right=1000000001,mid,minn,maxx,head,tail,now;

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(register int i=1;i<=n;i++)
		scanf("%d%I64d",&a[i].pos,&a[i].ans);
	a[0].pos=0;
	ans[0]=0;
	for (;left<right;)
	{
		mid=(left+right)/2;
		bool flag=0;

		head=0;tail=-1;now=0;
		minn=max (1,d-mid);
		maxx=d+mid;
		for(int i=1;i<=n;i++)
		{
			while(a[now].pos<=a[i].pos-minn)
			{
				while(tail>=head&&ans[now]>=q[tail].ans)
					tail--;
				tail++;
				q[tail].pos=a[now].pos;
				q[tail].ans=ans[now];
				now++;
			}
			while(head<=tail&&q[head].pos<a[i].pos-maxx) head++;
			if(head>tail)
				ans[i]=-10000000000000000LL;
			else
				ans[i]=q[head].ans+a[i].ans;
			if(ans[i]>=k)
			{
				flag=1;
				break;
			}
		}

		if(flag)
			right=mid;
		else
			left=mid+1;
	}
	if(left>1000000000)
		printf("-1\n");
	else
		printf("%d\n",left);
	return 0;
}
