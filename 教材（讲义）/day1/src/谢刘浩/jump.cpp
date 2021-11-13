#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

struct home{
	int len;
	long long num;
};

inline void read(int &x){
	char ch=getchar();int f=1;x=0;
	while(ch<'0'||ch>'9')
	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')
	{x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	x*=f;
}
inline void readl(long long &x){
	char ch=getchar();int f=1;x=0;
	while(ch<'0'||ch>'9')
	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')
	{x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	x*=f;
}
inline void print(int x){
	if(x>9)print(x/10);
	putchar(x%10+'0');
}

home a[600000];
long long ans[600000];
home q[600000];
int main()
{
	int n,d,k;
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	read(n);read(d);read(k);
	for(int i=1;i<=n;i++)read(a[i].len),readl(a[i].num);
	int l=0,r=1000000001;
	a[0].len=0;
	ans[0]=0;
	while(l<r)
	{
		int mid=(l+r)>>1;
		int head=0,tail=-1,now=0;
		int L=d-mid;
		int R=d+mid;
		if(L<=0)
			L=1;
		bool ok=false;
		for(int i=1;i<=n;i++)
		{
			while(a[now].len<=a[i].len-L)
			{
				while(tail>=head&&ans[now]>=q[tail].num)
					tail--;
				tail++;
				q[tail].len=a[now].len;
				q[tail].num=ans[now];
				now++;
			}
			while(head<=tail&&q[head].len<a[i].len-R)
				head++;
			if(head>tail)
				ans[i]=-10000000000000000LL;
			else
				ans[i]=q[head].num+a[i].num;
			if(ans[i]>=k)
			{ok=true;break;}
		}
		if(ok)
			r=mid;
		else
			l=mid+1;
	}
	if(l>1000000000)
	{putchar('-');putchar('1');}
	else
		print(l);
	return 0;
}
