#include<stdio.h>
struct point{
	int wz;
	long long ans;
};
point a[524288];
long long ans[524288];
point q[524288];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k;
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%I64d",&a[i].wz,&a[i].ans);
	}
	int l=0,r=1000000001;
	a[0].wz=0;
	ans[0]=0;
	while(l<r)
	{
		int mid=(l+r)>>1;
		int head=0,tail=-1,now=0;
		int lower=d-mid;
		int upper=d+mid;
		if(lower<=0)
		{
			lower=1;
		}
		bool ok=0;
		for(int i=1;i<=n;i++)
		{
			while(a[now].wz<=a[i].wz-lower)
			{
				while(tail>=head&&ans[now]>=q[tail].ans)
				{
					tail--;
				}
				tail++;
				q[tail].wz=a[now].wz;
				q[tail].ans=ans[now];
				now++;
			}
			while(head<=tail&&q[head].wz<a[i].wz-upper)
			{
				head++;
			}
			if(head>tail)
			{
				ans[i]=-10000000000000000LL;
			}
			else
			{
				ans[i]=q[head].ans+a[i].ans;
			}
			if(ans[i]>=k)
			{
				ok=1;
				break;
			}
		}
		if(ok)
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	if(l>1000000000)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n",l);
	}
	return 0;
}
