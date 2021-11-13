#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll oo=1000000000000000;

int n,d,k;
ll f[500005];
struct point{
	ll pos,val;
}a[500005];

template<class T> void read(T &re)
{
	re=0;
	T sign=1;
	char tmp;
	while((tmp=getchar())&&(tmp<'0'||tmp>'9')) if(tmp=='-') sign=-1;
	re=tmp-'0';
	while((tmp=getchar())&&(tmp>='0'&&tmp<='9')) re=(re<<3)+(re<<1)+(tmp-'0');
	re*=sign;
}

ll max(ll x,ll y)
{
	return x>y?x:y;
}

ll q[500005];

ll check(ll x)
{
	ll res=0;
	memset(f,-127,sizeof(f));
	//memset(q,0,sizeof(q));
	int h=1,t=1;
	ll lef=d+x,rig=max(d-x,1);
	q[1]=0;
	f[0] = 0;
	int id = 0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].pos<rig)	continue;
		if(a[i].pos-a[i-1].pos>lef)	break;
		if(!id)	id = i;
		while(id<=n && a[i].pos-a[id].pos>=rig)
		{
			while(f[q[t]]<=f[id] && h<=t) t--;
			q[++t] = id;
			id++;
		}
		while(a[i].pos-a[q[h]].pos>lef && h<=t)	h++;
		if(h>t)
			f[i]=-oo;
		else
			f[i]=f[q[h]]+a[i].val;
		res=max(res,f[i]);
		if(res>k)	return res;
	}
	return res;
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	read(n);read(d);read(k);
	for(int i=1;i<=n;i++)
	{
		read(a[i].pos);
		read(a[i].val);
	}
	ll l=0,r=oo,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid)>=k)
			r = mid-1;
		else
			l = mid+1;
	}
	printf("%lld",l<oo?l:-1);
	return 0;
}
